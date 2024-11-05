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
const ll N = 2e5+5;
ll pp = 1001;
using namespace std;

ll tt;
ll n,k,m,x,y,d;

ll inv[N]; 
ll fac[N];
ll ifac[N];

// calculate inverse
// for inv[k], let p = sk + r
// sk + r == 0 (mode p)
// sk(k^-1)(r^-1) + r(k^-1)(r^-1) == 0 (mode p)
// k^-1 == -s(r^-1) (mode p)
void initinv(){
	fac[0] = ifac[0] = inv[1] = fac[1] = ifac[1] = 1;
	for(int i = 2;i <= N-5;i++){
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

int main() {
	initinv();
	return 0;
}
