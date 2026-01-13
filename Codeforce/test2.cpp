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
const ll N = 200500;
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
ll n,k,m,t,x,y,z,h,q,d,s;

ll a[500500];
ll b[500500];

void md(ll & x){
	x = (x + p) % p;
}

ll ladder(ll x){
	return (1 + x) * x / 2;
}
ll sq(ll x){
	return x * x;
}
ll qpow(ll x, ll y){
    ll ans = 1;
    while(y){
        if(y&1) ans = ans * x % p;
        x = x * x % p,y>>=1;
    }
    return ans;
}

ll pow2[300500];
ll inv[300500];
ll fac[300500];
ll ifac[300500];
ll gm(ll x){
    while(x != (x & -x)){
        x -= x & -x;
    }
    return x;
}
ll wh(ll x){
	ll ret = 0;
	while(x){
		x >>= 1;
		ret++;
	}
	return ret - 1;
}
ll gt(ll lim, ll x){
	if(lim < 0)return 0;
	ll gmx = gm(x);
	ll whx = wh(x);
	ll cmore = 0, cless = 0, all = 0, cright = 0;
	for(ll i = 0;i <= lim;i++){
		if(((ll)1 << i) > gmx){
			cmore += a[i];
		}
		else if(((ll)1 << i) == gmx){
			cright += a[i];
		}
		else{
			cless += a[i];
		}
	}
	all = cmore + cless + cright;
	ll cnotmore = all - cmore;

	// ctest;csp(lim);csp(x);csp(cmore);csp(cless);csp(cright);csp(gmx);csp(whx);cendl;
	if(x == 0){
		return qpow(2, all);
	}

	ll ans = 0;
	if(cmore){
		// 2^(all - 1) + ... + 2^(all - cmore)
		ans += (qpow(2, all) - qpow(2, cnotmore) + p) % p;
		md(ans);
	}

	ll cons = 0, base = gmx;
	while(x & base){
		cons++;
		base >>= 1;
	}

	
	ll qpow2cless = qpow(2, cless);
	for(int i = cons + 1;i <= cright;i++){
		// choose i
		ll tans = fac[cright] * ifac[i] % p * ifac[cright - i] % p;
		tans = tans * qpow2cless % p;
		ans += tans;
		md(ans);
	}

	// ctest;csp(cons);cend(ans);
	
	if(cons <= cright){
		ll tans = fac[cright] * ifac[cons] % p * ifac[cright - cons] % p;
		// ctest;csp("tans ");csp(tans);cendl;

		ll tp = gmx;
		rep(ii,cons - 1){
			tp = tp | (tp >> 1);
		}

		tans *= gt(whx - 1, (x ^ tp) << 1);
		md(tans);
		ans += tans;
		md(ans);
	}

	return ans;
}

void sol(){
	// x = 100110
	// if choose a1 = 1000000, good
	// if choose a1 = 100000, then let others shrink half
	// if choose a1 = 10000, not good

	cin>>n>>m;
	rep(i,70){
		a[i] = 0;
	}
	rep1n(i,n){
		cin>>x;
		a[x]++;
	}
	rep(ii,m){
		cin>>x>>y;
		if(x == 1){
			n++;
			a[y]++;
		}
		else if(x == 2){
			n--;
			a[y]--;
		}
		else{
			ll lim = 60;
			ll ans = gt(lim, y);
			cend(ans);
		}
	}
}

ll tnt(){
	while(1){
	}
	return 0;
}


int main(){
	// ios_base::sync_with_stdio(false);
	// cin.tie(nullptr);
	// cout.tie(nullptr);


	pow2[0] = 1;
	pow2[1] = 2;
	inv[1] = fac[1] = ifac[1] = 1;
	fac[0] = ifac[0] = 1;
	for(int i = 2;i <= 300000;i++){
		pow2[i] = pow2[i - 1] * 2 % p;
		inv[i] = inv[p % i] * (p - p / i) % p;
		fac[i] = fac[i - 1] * i % p;
		ifac[i] = ifac[i - 1] * inv[i] % p;
	}

	tt = 1;
	// cin>>tt;
	for(ttt = 1;ttt <= tt;ttt++){
		sol();
	}
	system("pause");
	return 0;
}