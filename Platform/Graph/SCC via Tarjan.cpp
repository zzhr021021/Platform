// https://www.luogu.com.cn/problem/P3387
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1n(i, n) for (ll i = 1; i <= (n); ++i)
#define ll long long
#define vll vector<long long>
using namespace std;
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
ll tt, ttt;
ll n, k, m, t, x, y, z, h, q, d, s;

ll a[300050];

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
        dfn[i] = low[i] = scc[i] = sccsz[i] = sccval[i] = 0;
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
    tt = 1;
    // cin>>tt;
    for(ttt = 1;ttt <= tt;ttt++){
        sol();
    }
    return 0;
}