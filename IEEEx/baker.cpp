#include<bits/stdc++.h>
#define debug(x) cout << #x << " = " << x << endl
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (ll i = 1; i <= (n); ++i)
#define rep1nr(i, n) for (int i = (n); i >= 1; --i)
#define rep01n(i, n) for (int i = 0; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define replr(i, l, r) for (int i = l;i <= r;i++)
#define repij(i, j, n, m) for (int i = 0; i < (n); ++i) for (int j = 0; j < (m); ++j)

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
ll p = MOOD;
const ll inf = 1e18;
const ll INF = 1e18;
const ll N = 300500;
// ll dix[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
// ll diy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
using namespace std;
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
void ckmax(ll & x, ll y){
	if(y > x)x = y;
}
void ckmin(ll & x, ll y){
	if(y < x)x = y;
}
void printvec(vll & v){
	for(auto o : v){
		csp(o);
	}
	cendl;
}
ll tt, ttt;
ll n,k,m,t,x,y,z,h,q,d;

ll a[300500];

void md(ll & x){
	x = (x + p) % p;
}
ll ladder(ll x){
	return (1 + x) * x / 2;
}

const ll MMint = 1e6+5;
bool isp[MMint];
int primes[MMint];
int pp = 0;
int minprime[MMint];
bool mk[MMint];
ll mkp[MMint];
void sol(){
	cin>>x>>y;
	ll bn = 200000;
	if(y <= bn){
	    ll ans = 0;
	    for(int i = 2;i <= bn;i++){
	        ll cnt = 0;
	        if(isp[i]){
	            for(int ip = 0;ip < pp && primes[ip] < bn;ip++){
	                ll tp = i * primes[ip];
//	                ctest;csp(tp);
	                if(tp >= x && tp <= y){
	                    cnt++;
	                }
	                if(tp > y){
	                	break;
					}
	            }
	            cendl;
	        }
	        ans += ladder(cnt - 1);
	    }
	    cend(ans);
	}
	else{
	    
	}
}

int main(){
//	 ios_base::sync_with_stdio(false);
//	 cin.tie(nullptr);
//	 cout.tie(nullptr);
	 
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