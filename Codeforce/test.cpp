#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (ll i = 1; i <= (n); ++i)
#define rep1nr(i, n) for (int i = (n); i >= 1; --i)
#define rep01n(i, n) for (int i = 0; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define replr(i, l, r) for (int i = l;i <= r;i++)

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
const ll MOOD = 998244353;
ll p = MOOD;
const ll inf = 1e18;
const ll INF = 1e18;
const ll N = 200500;
// ll dix[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
// ll diy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
using namespace std;
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

void printvec(vll & v){
	for(auto o : v){
		csp(o);
	}
	cendl;
}

ll tt, ttt;
ll n,k,m,t,x,y,z,h,r;

<<<<<<< Updated upstream
ll dist[30][30];
ll op[200500];
char opt[200500];
void sol(){
	ll q;
	cin>>n>>q;
	rep(i,q){
		cin>>op[i]>>opt[i];
	}
	rep1n(u,n){
		rep1n(v,n){
			if(u == v)continue;
			ll posu = 0, posv = 0;
			ll d = 1;
			dist[u][v] = 1;
			rep(i,q){
				if(op[i] == u && opt[i] == '-'){
					d--;
				}
				else if(op[i] == v && opt[i] == '+'){
					d++;
				}
				dist[u][v] = max(dist[u][v], d);
			}
		}
	}
	
=======
ll pow2[200500];
ll a[200500];
ll segtree0p[800500];
ll segtree1p[800500];
ll segtree0q[800500];
ll segtree1q[800500];

void md(ll & x){
	x = (x + p) % p;
}
void maintain(ll o, ll seg[]){
	seg[o] = seg[o << 1] + seg[o << 1 | 1];
}
void add(ll o, ll l, ll r, ll pos, ll val, ll seg[]){
	ll mid = (l + r) >> 1;
	if(l == r){
		seg[o] += val;
		md(seg[o]);
		return;
	}
	if(o <= mid){
		add(o << 1, l, mid, pos, val, seg);
	}
	else{
		add(o << 1 + 1, mid + 1, r, pos, val, seg);
	}
}
ll query(ll o, ll L, ll R, ll l, ll r, ll seg[]){
	if(R < l || L > r)return 0;
	if(l >= L && r <= R)return a[o];
	ll mid = (l + r) >> 1;
	ll ret = 0;
	ret += query(o << 1    , L, R, l, mid, seg);
	md(ret);
	ret += query(o << 1 | 1, L, R, mid + 1, r, seg);
	md(ret);
	return ret;
}

// 0 - n-1
void sol(){
	string s;cin>>s;
	n = s.size();
	rep(i,4*(n+4)){
		segtree0p[i] = segtree1p[i] = segtree0q[i] = segtree1q[i] = 0;
	}
	rep(i,n){
		if(s[i] == '1'){
			add(1, 0, n - 1, i, 1, segtree1q);
			add(1, 0, n - 1, i, 1, segtree1p);
		}
		else{
			add(1, 0, n - 1, i, 1, segtree0q);
			add(1, 0, n - 1, i, 1, segtree0p);
		}
	}
	ll ans = 0;
	ll c0 = 0, c1 = 0, cc = 0;
	rep(i,n){
		ll oans = ans;
		ans += oans;
		md(ans);
		if(s[i] == '0'){
			ans += c1;
			md(ans);
		}
		else{
			ans += c0;
			md(ans);
		}
		ans++;
		md(ans);
		
		
		if(s[i] == '0'){
			c0 += cc;
			md(c0);
			c0++;
		}
		else{
			c1 += cc;
			md(cc);
			c1++;
		}
		cc = cc * 2 + 1;
		ctest;cend(ans);
	}
	cend(ans);
	
	ll q;cin>>q;
	rep(iq,q){
		cin>>x;
		// insert
		ans += ans;
		md(ans);
		ll cnt = 0;
		if(a[i] == '0'){
			
		}
		// delete
		
		// maintain segtree
		
		
		if(s[x] == '0'){
			s[x] = '1';
		}
		else{
			s[x] = '0';
		}
	}
>>>>>>> Stashed changes
}
	

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	pow2[0] = 1;
	rep1n(i, 200100){
		pow2[i] = pow2[i] * 2;
		md(pow2[i]);
	}
	
	tt = 1;
	cin>>tt;
	for(ttt = 1;ttt <= tt;ttt++){
		sol();
	}
	system("pause");
	return 0;
}
