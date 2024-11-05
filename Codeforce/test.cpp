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
const ll MOOD = 998244353;
ll p = MOD;
const ll inf = 1e18;
const ll INF = 1e18; 
// ll dix[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
// ll diy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
using namespace std;
// mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

ll tt, ttt;
ll n,k,m,d,t,x,y,z,h,q;

void printvec(vll & v){
	for(ll &x : v){
		cout << x << " ";
	}
	cendl;
}

ll qpow(ll x,ll y){
    ll ans = 1;
    while(y){
        if(y&1) ans = ans * x % MODD;
        x = x * x % MODD,y>>=1;
    }
    return ans;
}

ll a[100005];
bool vis[100005];
ll inv[100005];
ll fac[100005];
ll ifac[100005];

void sol(){
	cin>>n;
	rep1n(i,n){
		cin>>a[i];
		vis[i] = false;
	}
	ll ans = 1;
	ll cnt = 0;
	rep1n(i,n){
		if(vis[i] == false){
			cnt++;
			ll ringlen = 1;
			vis[i] = true;
			ll cur = a[i];
			while(vis[cur] == false){
				vis[cur] = true;
				ringlen++;
				cur = a[cur];
			}
			ll tp = 1;
			if(ringlen >= 2)tp = qpow(ringlen, ringlen - 2);
			ans = ans * tp % MODD;
			if(ringlen >= 2)ans = ans * ifac[ringlen - 1] % MODD;
		}
	}
	ans = ans * fac[n - cnt] % MODD;

	cend(ans);

}

int main(){
	// ios_base::sync_with_stdio(false);
	// cin.tie(nullptr);
	// cout.tie(nullptr);

	inv[1] = fac[1] = ifac[1] = fac[0] = ifac[0] = 1;
	for(int i = 2;i <= 100000;i++){
		inv[i] = inv[MODD % i] * (MODD - MODD / i) % MODD;
		fac[i] = fac[i - 1] * i % MODD;
		ifac[i] = ifac[i - 1] * inv[i] % MODD;
	}

	tt = 1;
	cin>>tt;
	for(ttt = 1;ttt <= tt;ttt++){
		sol();
	}
	system("pause");
	return 0;
}