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
#define cgap cout << "--------------------" << endl
#define pb push_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
 
#define alice cout<<"Alice\n"
#define bob cout<<"Bob\n"
#define draw cout<<"Draw\n"

const ll MOD = 1e9 + 7;
const ll MODD = 1e9 + 9;
const ll MOOD = 998244353;
ll p = MOD;
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
ll n,k,m,t,x,y,z;

ll h, w;
ll fac[200500];
ll ifac[200500];
ll inv[200500];
void initinv(){
	fac[0] = ifac[0] = inv[1] = fac[1] = ifac[1] = 1;
	for(int i = 2;i <= 200100;i++){
		inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD;
		fac[i] = fac[i - 1] * i % MOD;
		ifac[i] = ifac[i - 1] * inv[i] % MOD;
	}
}
ll C(ll u, ll d){
	ll ret = 1;
	ret *= fac[d];ret %= MOD;
	ret *= ifac[u];ret %= MOD;
	ret *= ifac[d - u];ret %= MOD;
	return ret;
}

ll a[200500];
ll dp[200500];
pll ve[200500];
bool cmp(const pll & u, const pll & v){
	if(u.first == v.first)return u.second < v.second;
	return u.first < v.first;
}
void sol(){
	cin>>h>>w>>n;
	rep1n(i,n){
		cin>>x>>y;
		ve[i] = {x, y};
	}
	sort(ve + 1, ve + 1 + n, cmp);
	n++;ve[n] = {h, w};
	rep1n(i,n){
		dp[i] = C(ve[i].first - 1, ve[i].first + ve[i].second - 2);
		for(int j = 1;j < i;j++){
			if(ve[j].first <= ve[i].first && ve[j].second <= ve[i].second){
				dp[i] -= dp[j] * C(ve[i].first - ve[j].first, ve[i].first - ve[j].first + ve[i].second - ve[j].second) % p;;
				dp[i] = (dp[i] + p) % p;
			}
		}
		// ctest;csp(i);csp(ve[i].first);csp(ve[i].second);csp(dp[i]);
		// csp(C(ve[i].first - 1, ve[i].first + ve[i].second - 2));cendl;
	}
	cend(dp[n]);

}

int main(){
	// ios_base::sync_with_stdio(false);
	// cin.tie(nullptr);
	// cout.tie(nullptr);
	initinv();
	tt = 1;
	// cin>>tt;
	for(ttt = 1;ttt <= tt;ttt++){
		sol();
	}
	system("pause");
	return 0;
}