#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)
#define rep1nr(i, n) for (int i = (n); i >= 1; --i)
#define rep01n(i, n) for (int i = 0; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)

#define ll long long
#define ull unsigned long long
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define vb vector<bool>
#define vpl vector<pair<long long, long long>>
#define smpq priority_queue<long long, vector<long long>, greater<long long>>
#define bgpq priority_queue<long long> 


#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define csp(n) cout << n << " "
#define cend(n) cout << n << endl
#define cendl cout << endl
#define ctest cout << "test   "
#define pb push_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
 
#define alice cout<<"Alice\n"
#define bob cout<<"Bob\n"
#define draw cout<<"Draw\n"

const ll MOD = 1e9;
const ll MODD = 1e9+9;
const ll MOOD = 998244353;
ll p = MOD;
const ll inf = 1e18;
const ll INF = 1e18; 
const int N = 200005;
using namespace std;
 
ll tt;
ll ttt;
ll n,k,m,d,q,t,x,y,z,h;
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

void printvec(vll & v){
	for(ll &x : v){
		cout << x << " ";
	}
	cendl;
}

vll g[200005];
ll c[200005];
ll sz[200005];
bool isleaf[200005];
ll heavy[200005];

ll colcnt[200005];
ll totcol = 0;
ll colccnt[200005];
ll totccol = 0;

ll ans[200005];

ll balancecnt = 0;

void addcnt(ll i){
    if(colccnt[i] == 0)totccol++;
    colccnt[i]++;
}
void delcnt(ll i){
    colccnt[i]--;
    if(colccnt[i] == 0)totccol--;
}

void add(ll o){
	if(colcnt[c[o]] == 0)totcol++;
	colcnt[c[o]]++;
    addcnt(colcnt[c[o]]);
    delcnt(colcnt[c[o]] - 1);
}
void del(ll o){
	colcnt[c[o]]--;
	if(colcnt[c[o]] == 0)totcol--;
    addcnt(colcnt[c[o]]);
    delcnt(colcnt[c[o]] + 1);
}

// process the size and heavy son.
void dfs0(ll o, ll fa){
	if(o != 1 && g[o].size() == 1){
		isleaf[o] = true;
	}

	sz[o] = 1;
	ll mx = 0;
	for(auto ad : g[o]){
		if(ad != fa){
			dfs0(ad, o);
			sz[o] += sz[ad];
			if(sz[ad] > mx){
				mx = sz[ad];
				heavy[o] = ad;
			}
		}
	}
}

void dfssubadd(ll o, ll fa){
	add(o);
	for(auto ad : g[o]){
		if(ad != fa){
			dfssubadd(ad, o);
		}
	}
}

void dfssubdel(ll o, ll fa){
	del(o);
	for(auto ad : g[o]){
		if(ad != fa){
			dfssubdel(ad, o);
		}
	}
}

void dfs1(ll o, ll fa, ll keep){
	for(auto ad : g[o]){
		if(ad != fa && ad != heavy[o]){
			dfs1(ad, o, false);
		}
	}
	if(!isleaf[o]){
		dfs1(heavy[o], o, true);
	}
	for(auto ad : g[o]){
		if(ad != fa && ad != heavy[o]){
			dfssubadd(ad, o);
		}
	}

	add(o);
	ans[o] = totcol;

    // ctest;csp(o);csp(totcol);csp( colccnt[sz[o] / totcol]);csp(sz[o]);cend(balancecnt);
    if(sz[o] % totcol == 0 && totcol == colccnt[sz[o] / totcol]){
        balancecnt++;
    }

	if(!keep){
		dfssubdel(o, fa);
	}
}

// Given a tree, each node is colored with c[i]
// Give m query, with query x, output the number of diffenct color, 
// in the subtree of node x
void sol(){
	cin>>n;
    rep1n(i,n){
        cin>>c[i];
        cin>>x;
        if(x == 0)continue;
        g[i].pb(x);
        g[x].pb(i);
    }

	dfs0(1, -1);
	dfs1(1, -1, false);
	
    cend(balancecnt);
	
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	tt = 1;
//	cin>>tt;
	for(ttt = 1;ttt <= tt;ttt++){
		sol();
	}
	system("pause");
	return 0;
}
