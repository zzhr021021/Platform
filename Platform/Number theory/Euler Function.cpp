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
const ll MOOD = 999911659;
ll p = MOD;
const ll inf = 1e18;
const ll INF = 1e18; 
// ll dix[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
// ll diy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
using namespace std;
// mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

ll tt, ttt;
ll n,k,m,t,x,y,z,h,q;

bool isp[10000005];
ll minprime[10000005];
ll primes[10000005];
ll pp = 0;
ll euler_value[10000005];
ll euler_value_presum[10000005];

void pre_mobius(){
	rep(i,10000005){
		isp[i] = true;
		minprime[i] = inf;
	}
	for(int i = 2;i <= 10000000;i++){
		if(isp[i]){
			primes[pp] = i;
			pp++;
			minprime[i] = i;
			for(int j = 2 * i;j <= 10000000;j += i){
				isp[j] = false;
				minprime[j] = min(minprime[j], (ll)i);
			}
		}
	}
	euler_value[1] = 1;
	for(int i = 2;i <= 10000000;i++){
		ll tp = minprime[i];
		if(i % (tp * tp) == 0)euler_value[i] = euler_value[i / tp] * tp;
		else euler_value[i] = euler_value[i / tp] * (tp - 1);
	}
	rep1n(i,10000000){
		euler_value_presum[i] = euler_value_presum[i - 1] + euler_value[i];
	}
}

void sol(){
	cin>>n;
	ll ans = 0;
	rep(i,pp){
		if(primes[i] > n)break;
		// ctest;cend(primes[i]);
		ans += 2 * euler_value_presum[n / primes[i]] - 1;
	}
	cend(ans);
}

int main(){
	// ios_base::sync_with_stdio(false);
	// cin.tie(nullptr);
	// cout.tie(nullptr);

	pre_mobius();

	tt = 1;
	// cin>>tt;
	for(ttt = 1;ttt <= tt;ttt++){
		sol();
	}
	system("pause");
	return 0;
}