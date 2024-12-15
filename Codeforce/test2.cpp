#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (ll i = 1; i <= (n); ++i)
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
ll p = MOOD;
const ll inf = 1e18;
const ll INF = 1e18;
const ll N = 1e6;
// ll dix[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
// ll diy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
using namespace std;
// mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

void printvec(vll & v){
	for(auto o : v){
		csp(o);
	}
	cendl;
}

ll tt, ttt;
ll n,k,m,t,x,y,z,h,r;

ll a,b,c;
ll d[3000005];

ll qpow(ll x,ll y){
    ll ans = 1;
    while(y){
        if(y&1) ans = ans * x % p;
        x = x * x % p,y>>=1;
    }
    return ans;
}
ll inv[3000005]; 
ll fac[3000005];
ll ifac[3000005];
void initinv(){
	fac[0] = ifac[0] = inv[1] = fac[1] = ifac[1] = 1;
	for(int i = 2;i <= 3000000;i++){
		inv[i] = inv[p % i] * (p - p / i) % p;
		fac[i] = fac[i - 1] * i % p;
		ifac[i] = ifac[i - 1] * inv[i] % p;
	}
} 
ll C(ll u, ll d){
	ll ret = 1;
	ret *= fac[d];ret %= p;
	ret *= ifac[u];ret %= p;
	ret *= ifac[d - u];ret %= p;
	return ret;
}
ll lcm(ll a, ll b, ll c){
	ll x = a * b / __gcd(a, b);
	return x * c / __gcd(x, c);
}
bool isp[3000005];
ll minprime[3000005];
ll primes[3000005];
ll pp = 0;
ll euler_value[3000005];
void pre_mobius(){
	rep(i,3000005){
		isp[i] = true;
		minprime[i] = inf;
	}
	for(int i = 2;i <= 3000000;i++){
		if(isp[i]){
			primes[pp] = i;
			pp++;
			minprime[i] = i;
			for(int j = 2 * i;j <= 3000000;j += i){
				isp[j] = false;
				minprime[j] = min(minprime[j], (ll)i);
			}
		}
	}
	euler_value[1] = 1;
	for(int i = 2;i <= 3000000;i++){
		ll tp = minprime[i];
		if(i % (tp * tp) == 0)euler_value[i] = euler_value[i / tp] * tp;
		else euler_value[i] = euler_value[i / tp] * (tp - 1);
	}
}
vll all_divs(ll x){
	vll ret;
	for(ll i = 1;i * i <= x;i++){
		if(x % i == 0){
			ret.push_back(i);
			if(i * i != x)ret.push_back(x / i);
		}
	}
	return ret;
}

void sol(){
	cin>>a>>b>>c>>k;
	ll g;
	rep(i,k){
		cin>>d[i];
		if(i == 0)g = d[i];
		else g = __gcd(g, d[i]);
	}
	ll ans = 0;
	
	map<ll, ll> rec;
	for(auto x : all_divs(a)){
		for(auto y : all_divs(b)){
			for(auto z : all_divs(c)){
				ll cycle = lcm(a / x, b / y, c / z);
				ll cnt = a * b * c / cycle;
				if(g % cycle)continue;

				ll tp = euler_value[a / x] * euler_value[b / y] * euler_value[c / z];
				rec[cnt] += tp;
			}
		}
	}
	for(auto cnto : rec){
		ll tp = cnto.second;
		ll rem = cnto.first;
		ll cycle = a * b * c / rem;
		ll tans = 1;
		rep(ii,k){
			tans *= C(d[ii] / cycle, rem);
			tans %= p;
			rem -= d[ii] / cycle;
		}
		ans = (ans + tans * tp % p) % p;
	}
	ans = ans * inv[a * b * c] % p;
	ans %= p;
	cend(ans);

}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	initinv();
	pre_mobius();

	tt = 1;
	cin>>tt;
	for(ttt = 1;ttt <= tt;ttt++){
		sol();
	}
	system("pause");
	return 0;
}