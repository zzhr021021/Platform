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

using namespace std;

const ll MMint = 1e6+5;
bool isp[MMint];
int primes[MMint];
int pp = 0;
int minprime[MMint];

void sol(){
	
	
}
int main() {
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
	
	ll n;cin>>n;
	rep(i,pp){
		ll p = primes[i];
		if(p > n)break;
		csp(p);
		ll ans = 0;
		ll cur = p;
		while(cur <= n){
			ans += n / cur;
			cur *= p;
		}
		cend(ans);
	}

	system("pause");
	return 0;
}
