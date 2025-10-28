#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (ll i = 1; i <= (n); ++i)
#define rep1nr(i, n) for (int i = (n); i >= 1; --i)
#define rep01n(i, n) for (int i = 0; i <= (n); ++i)

#define ll int
#define ull unsigned long long
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define vb vector<bool>
#define vpl vector<pair<long long, long long>>

#define csp(n) cout << n << " "
#define cend(n) cout << n << endl
#define cendl cout << endl
#define ctest cout << "test   "
#define pb push_back
#define all(a) a.begin(), a.end()

const ll inf = 1e9;
const ll INF = 1e9;
const ll N = 200500;
using namespace std;


ll tt, ttt;
ll n, k, m, t, x, y, z, h, q, d, s;

ll a[1000500];
ll inj[1000500];

vll g[1000500];

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
ll dfw(ll o, ll fa, ll dep){
    dw[o] = min(dw[o], dep);
    for(auto ad : g[o]){
        if(ad != fa && a[ad] != 1){
            dfw(ad, o, dep + 1);
        }
    }
    return 0;
}
ll up[1000500][21];
ll upmn[1000500][21];
ll de[1000500];
ll ff[1000500];
void dfl(ll o, ll fa, ll dep){
    de[o] = dep;
    ff[o] = fa;
    for(int i = 0;i <= 20;i++){
        if(i == 0){
            up[o][i] = fa;
            upmn[o][i] = dw[o];
        }
        else{
            if(up[o][i - 1] != -1){
                up[o][i] = up[up[o][i - 1]][i - 1];
                upmn[o][i] = min(upmn[o][i - 1], upmn[up[o][i - 1]][i - 1]);
            }
        }
    }
    for(auto ad : g[o]){
        if(ad != fa){
            dfl(ad, o, dep + 1);
        }
    }
}
ll upto(ll o, ll dis){
    if(dis == 0)return o;
    if(__builtin_popcount(dis) == 1){
        return up[o][inj[dis]];
    }
    ll m1 = dis & (-dis);
    ll om = m1;
    ll cnt = -1;
    while(cnt){
        cnt++;
        m1 >>= 1;
    }
    return upto(up[o][cnt], dis - om);
}
ll mnto(ll o, ll dis){
    if(dis == 1)return dw[o];
    if(__builtin_popcount(dis) == 1){
        return upmn[o][inj[dis]];
    }
    ll m1 = dis & (-dis);
    ll om = m1;
    ll cnt = -1;
    while(cnt){
        cnt++;
        m1 >>= 1;
    }
    // ctest;csp(o);cend(cnt);
    return min(upmn[o][cnt], mnto(up[o][cnt], dis - om));
    
}
ll lca(ll u, ll v){
    if(de[u] < de[v])swap(u, v);
    if(de[u] != de[v]){
        u = upto(u, de[u] - de[v]);
    }
    if(u == v)return u;
    if(ff[u] == ff[v])return ff[u];
    ll cnt = 0;
    while(up[u][cnt] != up[v][cnt]){
        cnt++;
    }
    cnt--;
    return lca(up[u][cnt], up[v][cnt]);
}

void sol(){ 
    memset(dw, 0x3f, sizeof(dw));
    memset(up, -1, sizeof(up));
    memset(upmn, 0x3f, sizeof(upmn));
    scanf("%d%d", &n, &q);
    rep1n(i,n){
        scanf("%d", &a[i]);
    }
    ll base = 1;
    rep(ii,21){
        inj[base] = ii;
        base *= 2;
    }
    rep(ie,n - 1){
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }

    rep1n(i,n){
        if(a[i] == 1){
            dfw(i, -1, 0);
        }
    }
    // lca
    dfl(1, -1, 0);

    rep(iq,q){
        scanf("%d%d", &l, &r);
        ll lc = lca(l, r);
        ll ans = inf;
        // ctest;csp(l);csp(r);csp(lc);csp(de[l] - de[lc]);cendl;
        ans = min(ans, mnto(l, de[l] - de[lc] + 1));
        // ctest;csp(ans);csp(l);csp(de[r] - de[lc] + 1);csp(upmn[6][1]);cendl;
        ans = min(ans, mnto(r, de[r] - de[lc] + 1));
        printf("%d\n", ans);
    }
    
}

int main(){
    sol();
	system("pause");
	return 0;
}