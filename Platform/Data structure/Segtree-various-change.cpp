// # Codeforce Div 921 2D
// # this example of segtree uses to lazy mark to record 2 thing:
// # 1. add x to all element in the seg
// # 2. from right to left, add x, 2x, 3x,... nx

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
const int N = 300005;
using namespace std;
 
ll tt;
ll n,k,m,d,q,f,h,w,t;

ll a[N];
ll b[300005];

ll v[300005];

ll stree[4*N];
ll lazy[4*N];
ll cazy[4*N];

ll cto(ll x){
	return (x + 1) * x / 2; 
}

void maintain(ll o){
	stree[o] = stree[o<<1] + stree[o<<1|1];
}

void propagate(ll o, ll l, ll r){
	if(l >= r)return;
	if(lazy[o] == 0 && cazy[o] == 0)return;
	ll mid = (l+r)>>1;
	ll c = lazy[o];
	ll d = cazy[o];
	lazy[o] = cazy[o] = 0;
	
	ll lo = o<<1, ro = o<<1|1;
	
	stree[lo] += (mid - l + 1) * c;
	stree[lo] += cto(mid - l + 1) * d;
	stree[lo] += (mid - l + 1) * d * (r - mid);
	lazy[lo] += c;
	cazy[lo] += d;
	lazy[lo] += d * (r - mid);
	
	stree[ro] += (r - mid) * c;
	stree[ro] += cto(r - mid) * d;
	lazy[ro] += c;
	cazy[ro] += d;
}

void buildtree(ll o, ll l, ll r){
	lazy[o] = cazy[o] = 0;
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

void change(ll o, ll l, ll r, ll cl, ll cr, ll c, ll d){
	if(l > cr || r < cl)return;
	if(l == r){
		stree[o] += c + d;
		return;
	}
	if(cl == l && r == cr){
		stree[o] += (r - l + 1) * c;
		stree[o] += cto(r - l + 1) * d;
		lazy[o] += c;
		cazy[o] += d;
		return;
	}
	propagate(o, l, r);
	ll mid = (l+r)>>1;
	if(cr <= mid){
		change(o<<1, l, mid, cl, cr, c, d);
	}
	else if(cl >= mid + 1){
		change(o<<1|1, mid + 1, r, cl, cr, c, d);
	}
	else{
		change(o<<1, l, mid, cl, mid, c + d * (cr - mid), d);
		change(o<<1|1, mid + 1, r, mid + 1, cr, c, d);
	}
	
	maintain(o);
	return;
}

ll query(ll o, ll l, ll r, ll L, ll R){
	if(r < L || l > R)return 0;
	if(L <= l && R >= r)return stree[o];
	if(l == r)return stree[o];
	
	propagate(o, l, r);
	
	ll mid = (l+r)>>1;
	ll ql = query(o<<1, l, mid, L, R);
	ll qr = query(o<<1|1, mid + 1, r, L, R);
	return ql + qr;
}

void sol(){
	cin>>n>>m>>q;
	set<ll> st;
	rep(i,m)cin>>a[i];
	rep(i,m)cin>>b[i];
	rep(i,m){
		st.insert(a[i]);
		v[a[i]] = b[i];
	}
	rep(i,n)a[i] = 0;
	for(int i = 1;i <= n;i++){
		if(v[i] != 0)a[i] = v[i];
		else a[i] = a[i - 1];
	}
	for(int i = n;i >= 0;i--){
		if(v[i] != 0)b[i] = 0;
		else b[i] = b[i + 1] + 1;
	}
	for(int i = 1;i <= n;i++){
		a[i] *= b[i];
	}
	
	buildtree(1, 0, n);
	rep(i,q){
		ll op,x,y;cin>>op>>x>>y;
		if(op == 1){
			v[x] = y;
			st.insert(x);
			auto po = st.find(x);
			auto pl = po;--pl;
			auto pr = po;++pr;
			if(*pl + 1 != *po){
				change(1, 0, n, *pl + 1, *po - 1, (*po - *pr) * v[*pl], 0);
			}
			if(*po + 1 != *pr){
				change(1, 0, n, *po + 1, *pr - 1, 0, (y - v[*pl]));
			}
			ll ori = query(1, 0, n, *po, *po);
			change(1, 0, n, *po, *po, -ori, 0);
		}
		else{
			cend(query(1, 0, n, x, y));
		}
	}
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	cin.tie(nullptr);
	tt = 1;
	while(tt--)sol();
	return 0;
}
