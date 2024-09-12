#include<bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)
using namespace std;
typedef long long ll;
using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pair<int, int>>;
using vvi = vector<vi>;

ll a[200005];
ll fac[200005];
ll t,m,n,k;
ll mod = 1e9+7;
ll p = 1e9+7;

vvi g(200005);
vector<unordered_map<ll,ll>> gss(200005);
ll side[200005][2];


ll qpow(ll x,ll y)
{
    ll ans=1;
    while(y)
    {
        if(y&1) ans=ans*x%p;
        x=x*x%p,y>>=1;
    }
    return ans;
}

ll C(ll x,ll y)
{
    if(x<y) return 0;
    return fac[x]*qpow(fac[y]*fac[x-y]%p,p-2)%p;
}

ll dfss(ll o, ll fa){
	ll ret = 1;
	rep(i, g[o].size()){
		int ad = g[o][i];
		if(ad != fa){
			int tp = dfss(ad, o);
			gss[o].emplace(ad,tp);
			ret += tp;
		}
	}
	if(fa != -1){
		gss[o].emplace(fa,n-ret);
	}
	return ret;
}

void sol(){
	cin >> n >> k;
	
	if(k%2==0){
		fac[0] = 1;
		for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
		ll up = 0;
		ll down = 0;
		down = C(n,k);
		rep1n(i,n){
			g[i].clear();
			gss[i].clear();
		}
		
		int x,y;
		rep(i,n - 1){
			cin >> x >> y;
			g[x].push_back(y);
			g[y].push_back(x);
			side[i][0] = x;
			side[i][1] = y;
		}
		
		dfss(1, -1);
		
		rep(i, n - 1){
			x = side[i][0];
			y = side[i][1];
			up += C(n - gss[x][y], k>>1) * C(n - gss[y][x], k>>1) % p;
			up %= mod;
		}
		cout << (up * qpow(down % mod, mod - 2) % mod + 1) % mod;
	}
	else{
		cout << 1 << endl;
	}
}
int main() {
	t = 1;
	while(t--){
		sol();
	}

	 
	return 0;
}
