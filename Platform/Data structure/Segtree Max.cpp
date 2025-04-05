#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)
#define rep1nr(i, n) for (int i = (n); i >= 1; --i)
#define rep01n(i, n) for (int i = 0; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)

#define ll long long
#define ull unsigned long long
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define vb vector<bool>

#define csp(n) cout << n << " "
#define cend(n) cout << n << endl
#define cendl cout << endl
#define ctest cout << "test   "
#define pb push_back
 
const ll MOD = 1e9 + 7;
const ll MODD = 1e9 + 9;
const ll MOOD = 666623333;
ll p = MOD;
const ll inf = 1e18;
const ll INF = 1e18; 
using namespace std;

ll tt, ttt;
ll n,k,m,t,x,y,z,h,q;

ll a[200005];
ll b[200005];
ll seg[800050];
ll lazy[800050];
void ckmax(ll & x, ll y){
	if(y > x)x = y;
}
ll get(ll o, ll l, ll r){
	return seg[o] + lazy[o];
}
void maintain(ll o, ll l, ll r){
	ll tp = -inf;
	ll mid = (l + r) / 2;
	ckmax(tp, get(o << 1, l, mid));
	ckmax(tp, get(o << 1 | 1, mid + 1, r));
	seg[o] = tp;
}
void propagate(ll o, ll l, ll r){
	seg[o] += lazy[o];
	if(l != r){
		ll mid = (l + r) / 2;
		lazy[o << 1] += lazy[o];
		lazy[o << 1 | 1] += lazy[o];
	}
	lazy[o] = 0;
}
void add(ll o, ll l, ll r, ll L, ll R, ll val){
	if(R < l || L > r)return;
	if(l >= L && r <= R){
		lazy[o] += val;
		return;
	}
	ll mid = (l + r) / 2;
	propagate(o, l, r);
	add(o << 1, l, mid, L, R, val);
	add(o << 1 | 1, mid + 1, r, L, R, val);
	maintain(o, l, r);
}
ll query(ll o, ll l, ll r, ll L, ll R){
	if(r < L || l > R)return -inf;
	if(l >= L && r <= R)return seg[o] + lazy[o];
	propagate(o, l, r);
	ll ret = -inf;
	ll mid = (l + r) / 2;
	ckmax(ret, query(o << 1, l, mid, L, R));
	ckmax(ret, query(o << 1 | 1, mid + 1, r, L, R));
	return ret;
}

void sol(){
	// input 
	cin>>n;
	rep1n(i,n){
		cin>>a[i];
		add(1, 1, n, i, i, a[i]);
	}

}

int main(){
	// ios_base::sync_with_stdio(false);
	// cin.tie(nullptr);
	// cout.tie(nullptr);

	tt = 1;
	// cin>>tt;
	for(ttt = 1;ttt <= tt;ttt++){
		sol();
	}
	system("pause");
	return 0;
}