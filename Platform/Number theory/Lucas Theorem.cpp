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
const ll MOD = 3;
const ll inf = 1e18;
const ll N = 2e5+5;
ll pp = 1001;
using namespace std;

ll tt;
ll n,k,m,x,y,d;

ll inv[N], fac[N], ifac[N];
void initinv(){
	fac[0] = ifac[0] = inv[1] = fac[1] = ifac[1] = 1;
	for(int i = 2;i <= N-5;i++){
		inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD;
		fac[i] = fac[i - 1] * i % MOD;
		ifac[i] = ifac[i - 1] * inv[i] % MOD;
	}
} 

// lucas theorem is to calculate combination when MOD is small
ll C(ll u, ll d){
    if(u > d)return 0;
    if(u == 0)return 1;
    ll ret = 1;
    if(d% p - u % p < 0){
        return 0;
    }
    else{
        ret *= fac[d % p];ret %= p;
        ret *= ifac[u % p];ret %= p;
        ret *= ifac[d % p - u % p];ret %= p;
    }
    ret *= C(u / p, d / p);ret %= p;
    return ret;
}

int main() {
	initinv();
	return 0;
}
