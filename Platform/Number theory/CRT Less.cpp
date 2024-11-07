#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)

#define ll long long

#define csp(n) cout << n << " "
#define cend(n) cout << n << endl
#define cendl cout << endl
#define ctest cout << "test   "

const ll MOD = 1e9 + 7;
const ll MODD = 1e9 + 9;
const ll MOOD = 999911659;
ll p = MOD;
const ll inf = 1e18;
using namespace std;
ll tt, ttt;
ll n,k,m,d,q;

ll qpow(ll x, ll y, ll p){
    ll ans = 1;
    while(y){
        if(y&1) ans = ans * x % p;
        x = x * x % p,y>>=1;
    }
    return ans;
}

ll primes[4] = {2, 3, 4679, 35617};
ll inv[4][100005];
ll fac[4][100005];
ll ifac[4][100005];
ll val;

ll C(ll u, ll d, ll ip){
	ll mod = primes[ip];
    if(u > d)return 0;
    if(u == 0)return 1;
    ll ret = 1;
    ret *= fac[ip][d % mod];ret %= mod;
    ret *= ifac[ip][u % mod];ret %= mod;
    ret *= ifac[ip][d % mod - u % mod];ret %= mod;
    ret *= C(u / mod, d / mod, ip);ret %= mod;
	return ret;
}

ll a[4];
ll b[4];

void proc(ll d){
	rep(ip, 4){
		ll mod = primes[ip];
		a[ip] += C(d, n, ip);
		a[ip] %= mod;
	}
}

void CRT(){
	// mod is a not very big inprime
	ll mod = 999911659 - 1;
	for(ll i = 0;i < 4;i++){
		val = (val + a[i] * (mod / b[i]) % mod * qpow(mod / b[i], b[i] - 2,b[i])) % mod;
    }
}

void sol(){
	for(int ip = 0;ip < 4;ip++){
		ll mod = primes[ip];
		fac[ip][0] = ifac[ip][0] = inv[ip][1] = fac[ip][1] = ifac[ip][1] = 1;
		for(int i = 2;i <= mod - 1;i++){
			inv[ip][i] = inv[ip][mod % i] * (mod - mod / i) % mod;
			fac[ip][i] = fac[ip][i - 1] * i % mod;
			ifac[ip][i] = ifac[ip][i - 1] * inv[ip][i] % mod;
		}
	}

	cin>>n>>q;
	if(q == MOOD){
		cout << "0" << endl;
		return;
	}
	for(int i = 1;i * i <= n;i++){
		if(n % i == 0){
			if(i * i == n){
				proc(i);
			}
			else{
				proc(i);proc(n / i);
			}
		}
	}
	rep(i,4)b[i] = primes[i];

	CRT();
	// ll xk = 0;
	// ll mk = 1;
	// ll thelcm = 1;
	// rep(i,4){
	// 	auto tp = eucl(mk, b[i]);
	// 	ll am = (a[i] - xk) / tp.d * tp.x;
	// 	ll ax = xk + mk * am;
	// 	thelcm = thelcm * b[i] / eucl(thelcm, b[i]).d;
	// 	mk = thelcm;
	// 	xk = (ax % mk + mk) % mk;
	// }
	cend(qpow(q, val, MOOD));



}

int main(){
	tt = 1;
	// cin>>tt;
	for(ttt = 1;ttt <= tt;ttt++){
		sol();
	}
	system("pause");
	return 0;
}