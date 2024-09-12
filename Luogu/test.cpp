#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)
#define rep01n(i, n) for (int i = 0; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define csp(n) cout << n << " "
#define cend(n) cout << n << endl
#define cendl cout << endl
#define ctest cout << "test\n"

typedef long long ll;
const ll MOD = 998244353;
const ll inf = 1e18;
using namespace std;

ll tt;
ll n,k,m,x,y,d;
const ll MMint = 1e5+5;
bool isp[MMint];
int primes[MMint];
int pp = 0;
int minprime[MMint];

ll a[300005];
ll inv[100005];

void sol(){
	ll t;
	cin>>x>>t;
	if(x == 1){
		rep(ttt,t){
			cin>>n;
			if(n == 1){
				cout << "2 1\n";
			}
			else if(n & 1){
				cend(0);
			}
			else{
				csp(2);
				rep(i,n){
					if(i&1){
						csp(i);
					}
					else{
						csp(n-i);
					}
				}
				cendl;
			}
		}
	}
	else{
		rep(ttt,t){
			cin>>n;
			if(isp[n]){
				csp(2);
				inv[1] = 1;
				csp(1);
				for(int i = 2;i <= n - 1;i++){
					inv[i] = inv[n % i] * (n - n / i) % n;
				}
				for(int i = 1;i <= n - 2;i++){
					csp(inv[i] + 1);
				}
				csp(n);
				cendl;
			}
			else if(n == 1){
				csp(2);
				cout << "1\n";
			}
			else if(n == 4){
				csp(2);
				cout << "1 3 2 4\n";
			}
			else{
				cend(0);
			}
		}
	}
}
int main() {
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
	
	tt=1;
	while(tt--)sol();
	return 0;
}
