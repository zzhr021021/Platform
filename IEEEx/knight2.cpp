#include <bits/stdc++.h>
#define debug(x) cout << #x << " = " << x << endl
#define vdebug(a)         \
	cout << #a << " = ";  \
	for (auto x : a)      \
		cout << x << " "; \
	cout << "\n";

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (ll i = 1; i <= (n); ++i)
#define rep1nr(i, n) for (int i = (n); i >= 1; --i)
#define rep01n(i, n) for (int i = 0; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define replr(i, l, r) for (int i = l; i <= r; i++)
#define repij(i, j, n, m)         \
	for (int i = 0; i < (n); ++i) \
		for (int j = 0; j < (m); ++j)

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

#define yes cout << "YES\n"
#define no cout << "NO\n"
#define csp(n) cout << n << " "
#define cend(n) cout << n << endl
#define cendl cout << endl
#define ctest cout << "test   "
#define cgap cout << "--------------------" << endl
#define pb push_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

#define alice cout << "Alice\n"
#define bob cout << "Bob\n"
#define draw cout << "Draw\n"

const ll MOD = 1e9 + 7;
const ll MODD = 1e9 + 9;
const ll MOOD = 998244353;
ll p = MOD;
const ll inf = 1e18;
const ll INF = 1e18;
const ll N = 200500;
// ll dix[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
// ll diy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
using namespace std;
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM =
            std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

void ckmax(ll &x, ll y)
{
	if (y > x)
		x = y;
}
void ckmin(ll &x, ll y)
{
	if (y < x)
		x = y;
}
void printvec(vll &v)
{
	for (auto o : v)
	{
		csp(o);
	}
	cendl;
}
ll tt, ttt;
ll n, k, m, t, x, y, z, h, q, d, s;

ll a[1000500];

ll md(ll x)
{
	return (x % p + p) % p;
}
ll qpow(ll x,ll y){
    ll ans = 1;
    while(y){
        if(y&1) ans = ans * x % p;
        x = x * x % p,y>>=1;
    }
    return ans;
}
ll ladder(ll l, ll r){
	return (l + r) * (r - l + 1) / 2;
}

vll g[1000500];
bool mk[1000500];

ll l, r;
bool dfs1(ll o, ll fa){
    ll ret = false;
    for(auto ad : g[o]){
        if(ad != fa){
            bool tp = dfs1(ad, o);
            ret = ret | tp;
        }
    }
    if(o == r){
        ret = true;
    }
    mk[o] = ret;
    return ret;
}
ll dfs2(ll o, ll fa){
    if(a[o] == 1){
        return 0;
    }
    ll dis = inf;
    for(auto ad : g[o]){
        if(ad != fa){
            dis = min(dis, dfs2(ad, o) + 1);
        }
    }
    return dis;
}
ll dw[1000500];
ll ff[1000500];
ll de[1000500];
ll dfw(ll o, ll fa, ll dep){
    dw[o] = min(dw[o], dep);
    for(auto ad : g[o]){
        if(ad != fa && a[ad] != 1){
            dfw(ad, o, dep + 1);
        }
    }
    return 0;
}
void dfs1(ll o, ll fa, ll dep){
    de[o] = dep;
    ff[o] = fa;
    for(auto ad : g[o]){
        if(fa != ad){
            dfs1(ad, o, dep + 1);
        }
    }
}
void sol(){
    memset(dw, 0x3f, sizeof(dw));
    cin>>n>>q;
    rep1n(i,n)cin>>a[i];
    rep(ie,n - 1){
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    rep1n(i,n){
        if(a[i] == 1){
            dfw(i, -1, 0);
        }
    }
    dfs1(1, -1, 0);

    rep(iq,q){
        cin>>l>>r;
        ll ans = inf;
        if(de[l] < de[r]){
            swap(l, r);
        }
        while(de[l] > de[r]){
            ans = min(ans, dw[l]);
            l = ff[l];
        }
        while(l != r){
            ans = min(ans, dw[l]);
            ans = min(ans, dw[r]);
            l = ff[l];
            r = ff[r];
        }
        ans = min(ans, dw[l]);
        cend(ans);
    }
    
}

int main(){

	// ios_base::sync_with_stdio(false);
	// cin.tie(nullptr);
	// cout.tie(nullptr);


	tt = 1;
	// cin >> tt;
	for (ttt = 1; ttt <= tt; ttt++)
	{
		sol();
	}
	system("pause");
	return 0;
}