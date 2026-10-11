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
const ll MOOD = 676767677;
ll p = MOOD;
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

ll a[300050];
ll b[300050];

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

// https://www.luogu.com.cn/problem/P3387
// original graph
vll g[200500];
// data for tarjan and scc
// dfn means depth first number
ll dfn[200050], low[200500], tick, scc[200500];
bool instack[200500];
stack<ll> dst;
ll scccnt, sccsz[200500], sccval[200500];
void tarjan(ll o){
    tick++;
    low[o] = dfn[o] = tick;
    dst.push(o);
    instack[o] = true;
    for(auto ad : g[o]){
        if(dfn[ad] == 0){
            tarjan(ad);
            ckmin(low[o], low[ad]);
        }
        else if(instack[ad]){
            ckmin(low[o], dfn[ad]);
        }
    }
    // find a scc
    if(dfn[o] == low[o]){
        scccnt++;
        while(dst.top() != o){
            ll oo = dst.top();
            scc[oo] = scccnt;sccsz[scccnt]++;sccval[scccnt] += a[oo];instack[oo] = false;
            dst.pop();
        }
        ll oo = dst.top();
        scc[oo] = scccnt;sccsz[scccnt]++;sccval[scccnt] += a[oo];instack[oo] = false;
        dst.pop();
    }

}
// scc graph
vll sccg[200500];
ll indeg[200500];
ll dp[200500];

void sol(){
    cin>>n>>m;
    // clear
    tick = scccnt = 0;
    rep1n(i,n){
        g[i].clear();
        sccg[i].clear();
        instack[i] = false;
        dfn[i] = low[i] = scc[i] = sccsz[i] = 0;
        indeg[i] = dp[i] = 0;
    }
    // input
    rep1n(i,n){
        cin>>a[i];
    }
    rep(ni,m){
        cin>>x>>y;
        g[x].push_back(y);
    }
    // get scc
    rep1n(i,n){
        if(scc[i] == 0){
            tarjan(i);
        }
    }
    // topo sort and output
    rep1n(i,n){
        for(auto j : g[i]){
            ll u = scc[i];
            ll v = scc[j];
            if(u != v){
                sccg[u].push_back(v);
                indeg[v]++;
            }
        }
    }
    // use queue to topo sort and output
    ll ans = 0;
    queue<ll> q;
    rep1n(i,scccnt){
        dp[i] = sccval[i];
        if(indeg[i] == 0){
            q.push(i);
        }
    }
    while(q.size()){
        auto o = q.front();q.pop();
        ckmax(ans, dp[o]);
        for(auto ad : sccg[o]){
            dp[ad] = max(dp[ad], sccval[ad] + dp[o]);
            indeg[ad]--;
            if(indeg[ad] == 0){
                q.push(ad);
            }
        }
    }
    cend(ans);

}


ll tnt(){
    while(1){
    }
    return 0;
}


int main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);

    tt = 1;
    // cin>>tt;
    for(ttt = 1;ttt <= tt;ttt++){
        sol();
    }
    system("pause");
    return 0;
}