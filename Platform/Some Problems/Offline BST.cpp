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
#define vpl vector<pair<long long, long long>>
#define vstr vector<string>
#define smpq priority_queue<long long, vector<long long>, greater<long long>>
#define bgpq priority_queue<long long> 

#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define csp(n) cout << n << " "
#define cend(n) cout << n << endl
#define cendl cout << endl
#define ctest cout << "test   "
#define pb push_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
 
#define alice cout<<"Alice\n"
#define bob cout<<"Bob\n"
#define draw cout<<"Draw\n"


const ll MOD = 1e9 + 7;
const ll MODD = 1e9 + 9;
const ll MOOD = 666623333;
ll p = MOD;
const ll inf = 1e18;
const ll INF = 1e18; 
// ll dix[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
// ll diy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
using namespace std;
// mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

ll tt, ttt;
ll n,k,m,t,x,y,z,h,q;

ll optp[100005];
ll opx[100005];
set<ll> xs;
map<ll, ll> inj;
map<ll, ll> jni;

ll a[100010];
ll seg[400050];
ll lazy[400050];
void init(){

}
ll get(ll o, ll l, ll r){
	return seg[o] + lazy[o] * (r - l + 1);
}
void maintain(ll o, ll l, ll r){
	ll tp = 0;
	ll mid = (l + r) / 2;
	tp += get(o << 1, l, mid);
	tp += get(o << 1 | 1, mid + 1, r);
	seg[o] = tp;
}
void propagate(ll o, ll l, ll r){
	seg[o] += lazy[o] * (r - l + 1);
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
	if(r < L || l > R)return 0;
	if(l >= L && r <= R)return seg[o] + lazy[o] * (r - l + 1);
	propagate(o, l, r);
	ll ret = 0;
	ll mid = (l + r) / 2;
	ret += query(o << 1, l, mid, L, R);
	ret += query(o << 1 | 1, mid + 1, r, L, R);
	return ret;
}

// an offline BST, using segment tree to fake
void sol(){
	// input 
	cin>>n;
	rep(i,n){
		cin>>optp[i]>>opx[i];
		xs.insert(opx[i]);
	}
	ll cnt = 0;
	xs.insert(-inf);
	xs.insert(inf);
	for(auto o : xs){
		inj[o] = cnt;
		jni[cnt] = o;
		cnt++;
	}

	m = 1e5 + 10;
	rep(i,n){
		x = optp[i];y = opx[i];
		ll ans;
		if(x == 1){
			y = inj[y];
			add(1, 0, m - 1, y, y, 1);
		}
		else if(x == 2){
			y = inj[y];
			add(1, 0, m - 1, y, y, -1);
		}
		else if(x == 3){
			y = inj[y];
			ans = query(1, 0, m - 1, 0, y - 1);
			cend(ans + 1);
		}
		else if(x == 4){
			ll l = 0, r = m - 1;
			while(l != r){
				// ctest;
				// csp(l);csp(r);cendl;
				ll mid = (l + r) / 2;
				if(query(1, 0, m - 1, 0, mid) < y)l = mid + 1;
				else r = mid;
			}
			ans = jni[l];
			cend(ans);
		}
		else if(x == 5){
			y = inj[y];
			ll pv = y - 1;
			ll l = 0, r = pv;
			while(l != r){
				ll mid = (l + r + 1) / 2;
				if(query(1, 0, m - 1, mid, pv) == 0)r = mid - 1;
				else l = mid;
			}
			ans = jni[l];
			cend(ans);
		}
		else{
			y = inj[y];
			ll pv = y + 1;
			ll l = pv, r = m - 1;
			while(l != r){
				ll mid = (l + r) / 2;
				if(query(1, 0, m - 1, pv, mid) == 0)l = mid + 1;
				else r = mid;
			}
			ans = jni[l];
			cend(ans);
		}
	}

}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	tt = 1;
	// cin>>tt;
	for(ttt = 1;ttt <= tt;ttt++){
		sol();
	}
	system("pause");
	return 0;
}