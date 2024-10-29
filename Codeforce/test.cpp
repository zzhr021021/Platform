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


const ll MOD = 1e9;
const ll MODD = 1e9+9;
const ll MOOD = 998244353;
ll p = MOD;
const ll inf = 1e18;
const ll INF = 1e18; 
const int N = 200005;
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

const ll MMint = 1e5+5;
bool isp[MMint];
int primes[MMint];
int pp = 0;
int minprime[MMint];

ll work(ll ma, ll mb, ll mc, ll md){
	if(mc > ma || md < mb)return 0;
	if(ma > mc && mb < md && mc == md)return 1;
	if(ma == mc && mb < md && mc <= md)return 1;
	if(ma > mc && mb == md && mc <= md)return 1;
	if(ma == mc && mb == md && mc <= md)return md - mc + 1;
	return 0;
}

void sol(){
	ll a,b,c,d;cin>>a>>c>>b>>d;
	ll ans = 1;
	ll x = d;
	rep(i,pp){
		ll prm = primes[i];
		if(x % prm == 0){
			ll ma = 0, mb = 0, mc = 0, md = 0;
			while(a % prm == 0){ma++;a /= prm;}
			while(b % prm == 0){mb++;b /= prm;}
			while(c % prm == 0){mc++;c /= prm;}
			while(d % prm == 0){md++;d /= prm;}
			ans *= work(ma, mb, mc, md);
		}
		if(ans == 0)break;
	}
	if(ans == 0){
		cend(ans);return;
	}
	if(d != 1){
		ll ma = 0, mb = 0, mc = 0, md = 0;
		while(a % d == 0){ma++;a /= d;}
		while(b % d == 0){mb++;b /= d;}
		while(c % d == 0){mc++;c /= d;}
		md = 1;
		ans *= work(ma, mb, mc, md);
	}
	cend(ans);

}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// Sieve of Eratosthenes
	for(int i = 0;i < MMint;i++){
		isp[i] = true;
		minprime[i] = i;
	}
	isp[0] = isp[1] = false;
	for(int i = 2;i < MMint;i++){
		if(isp[i]){
			primes[pp] = i;
			pp++;
		}
		for(int j = 0;j < pp;j++){
			int p = primes[j];
			int mul = i * p;
			if(mul < MMint){
				isp[mul] = false;
				minprime[mul] = p;
			}
			else{
				break;
			}
			if(i % p == 0){
				break;
			}
		}
	}

	tt = 1;
	cin>>tt;
	for(ttt = 1;ttt <= tt;ttt++){
		sol();
	}
	system("pause");
	return 0;
}