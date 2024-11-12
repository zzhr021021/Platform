#include<bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define rep1(i, n) for (ll i = 1; i < (n); ++i)
#define rep1n(i, n) for (ll i = 1; i <= (n); ++i)
#define rep1nr(i, n) for (ll i = (n); i >= 1; --i)
#define rep01n(i, n) for (ll i = 0; i <= (n); ++i)
#define repr(i, n) for (ll i = (n) - 1; i >= 0; --i)

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

bool isp[1000005];
ll primes[1000005];
ll pp = 0;
ll minprime[1000005];

int main() {
	for(ll i = 2;i < 1000005;i++){
		isp[i] = true;
		minprime[i] = i;
	}
	isp[0] = isp[1] = false;
	for(ll i = 2;i < 1000000;i++){
		if(isp[i]){
			primes[pp] = i;
			pp++;
			for(ll j = 2 * i;j <= 1000000;j += i){
				isp[j] = false;
				minprime[j] = min(minprime[j], i);
			}
		}
	}


	ll l, r;
	while(cin>>l>>r){
		vector<bool> ispoff(r - l + 1, true);
		vector<ll> primesoff;
		rep(i,pp){
			ll p = primes[i];
			if(p * p > r)break;
			for(ll j = l / p * p;j <= r;j += p){
				if(j == p)continue;
				if(j < l)continue;
				ispoff[j - l] = false;
			}
		}
		rep(i,r - l + 1){
			if(ispoff[i]){
				primesoff.push_back(l + i);
			}
		}
		
		ll pcnt = 0;
		pcnt = primesoff.size();
		if(pcnt <= 1){
			cend("There are no adjacent primes.");
		}
		else{
			ll x1, y1, x2, y2;
			x1 = 0;y1 = 1e9;
			x2 = 0;y2 = 0;
			rep(i,primesoff.size() - 1){
				ll x = primesoff[i];
				ll y = primesoff[i + 1];
				if(y - x < y1 - x1){
					x1 = x;
					y1 = y;
				}
				if(y - x > y2 - x2){
					x2 = x;
					y2 = y;
				}
			}
			cout << x1 << "," << y1 << " are closest, " << x2 << "," << y2 << " are most distant.";
			cendl;
		}	
	}
	system("pause");
	return 0;
}
