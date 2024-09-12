#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)
#define rep01n(i, n) for (int i = 0; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define csp(n) cout << n << " "
#define cend(n) cout << n << endl
#define cendl cout << endl
#define ctest cout << "test\n"
 
#define alice cout<<"Alice\n"
#define bob cout<<"Bob\n"
#define draw cout<<"Draw\n"
 
typedef long long ll;
const ll MOD = 999999893;
ll p = MOD;
const ll inf = 2e9+5;
using namespace std;
 
ll tt;
ll n,k,m,d,q,f,h,w,t;
const int N = 300005;

ll a[N];
ll stree[4*N];
ll lazy[4*N];

void maintain(ll o){
	stree[o] = stree[o<<1] + stree[o<<1|1];
}

void propagate(ll o, ll l, ll r){
	if(l >= r)return;
	ll mid = (l+r)>>1;
	ll dif = lazy[o];
	lazy[o] = 0;
	
	stree[o<<1] += dif * (mid - l + 1);
	lazy[o<<1] += dif;
	if(l == mid)lazy[o<<1] = 0;
	
	stree[o<<1|1] += dif * (r - mid);
	lazy[o<<1|1] += dif;
	if(mid + 1 == r)lazy[o<<1|1] = 0;
}

void buildtree(ll o, ll l, ll r){
	lazy[o] = 0;
	if(l == r){
		stree[o] = a[l];
		return;
	}
	ll mid = (l+r)>>1;
	buildtree(o<<1, l, mid);
	buildtree(o<<1|1, mid + 1, r);
	maintain(o);
	return;
}

void change(ll o, ll l, ll r, ll cl, ll cr, ll dif){
	if(l > cr || r < cl)return;
	if(l == r){
		stree[o] += dif;
		return;
	}
	if(cl <= l && r <= cr){
		stree[o] += dif * (r - l + 1);
		lazy[o] += dif;
		return;
	}
	if(lazy[o] != 0){
		propagate(o, l, r);
	}
	ll mid = (l+r)>>1;
	change(o<<1, l, mid, cl, cr, dif);
	change(o<<1|1, mid + 1, r, cl, cr, dif);
	maintain(o);
	return;
}

ll query(ll o, ll l, ll r, ll L, ll R){
	if(r < L || l > R)return 0;
	if(L <= l && R >= r)return stree[o];
	
	if(lazy[o] != 0){
		propagate(o, l, r);
	}
	
	ll mid = (l+r)>>1;
	ll ql = query(o<<1, l, mid, L, R);
	ll qr = query(o<<1|1, mid + 1, r, L, R);
	return ql + qr;
}

int main(){
	rep(i,15){
		a[i] = i;
	}
	buildtree(1, 0, 14);
	ctest;rep(i,15)csp(query(1, 0, 14, i, i));
	change(1, 0, 14, 0, 4, 2);
	ctest;rep(i,15)csp(query(1, 0, 14, i, i));
	change(1, 0, 14, 2, 5, 7);
	ctest;rep(i,15)csp(query(1, 0, 14, i, i));
	cout << query(1, 0, 14, 3, 5) << endl;
	return 0;
}
