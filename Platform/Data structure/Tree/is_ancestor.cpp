#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)
#define rep1nr(i, n) for (int i = (n); i >= 1; --i)
#define rep01n(i, n) for (int i = 0; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define csp(n) cout << n << " "
#define cend(n) cout << n << endl
#define cendl cout << endl
#define ctest cout << "test   "
#define pb push_back
 
#define alice cout<<"Alice\n"
#define bob cout<<"Bob\n"
#define draw cout<<"Draw\n"
 
typedef long long int ll;
const ll MOD = 1e9+1e6;
ll p = MOD;
const ll inf = 1e18;
const int N = 3e5+5;
using namespace std;
 
ll tt;
ll ttt;
ll n,k,m,d,q,f,h,w,c,t;

// https://codeforces.com/contest/1935/problem/F
// description : for a tree, for each vertex, delete it then restore it, ask every components min, max id, after the delete operation.

ll a[N];
vector<ll> g[N];
ll tin[N];
ll tout[N];
// info about subtree component
ll l0[N];
ll r0[N];
// info about 'father' component 
ll lup[N];
ll rup[N];
// direct father
ll dfa[N];
// traverse order
vector<ll> ord;

ll timer = 0;

void dfs(ll o, ll fa){
	l0[o] = r0[o] = o;
	dfa[o] = fa;
	tin[o] = timer++;
	ord.pb(o);
	for(ll ad : g[o]){
		if(ad != fa){
			dfs(ad, o);
			l0[o] = min(l0[o], l0[ad]);
			r0[o] = max(r0[o], r0[ad]);
		}
	}
	tout[o] = timer - 1;
}

bool isa(ll o, ll w){
	return tin[o] <= tin[w] && tout[o] >= tout[w];
}

void sol(){
	// read tree with n vertices
	cin>>n;
	rep(i,n+1)g[i].clear();
	rep(i,n-1){
		ll x,y;cin>>x>>y;x--;y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	timer = 0;
	ord.clear();
	dfs(0, -1);
	
	vector<ll> pref_min_ord(n + 1, n), suf_min_ord(n + 1, n);
    vector<ll> pref_max_ord(n + 1, -1), suf_max_ord(n + 1, -1);
	for (int i = 0; i < n; i++) {
        pref_min_ord[i + 1] = min(pref_min_ord[i], ord[i]);
        pref_max_ord[i + 1] = max(pref_max_ord[i], ord[i]);
    }
    for (int i = n - 1; i >= 0; i--) {
        suf_min_ord[i] = min(suf_min_ord[i + 1], ord[i]);
        suf_max_ord[i] = max(suf_max_ord[i + 1], ord[i]);
    }
    for (int id = (int)ord.size() - 1; id >= 0; id--) {
        int v = ord[id];
        lup[v] = min(pref_min_ord[tin[v]], suf_min_ord[tout[v] + 1]);
        rup[v] = max(pref_max_ord[tin[v]], suf_max_ord[tout[v] + 1]);
    }
    
    rep(i,n){
    	ll cnt = 0;
    	ll coin = 0;
    	vector<array<ll, 2>> compo;
    	vector<array<ll, 2>> ans;
    	for(ll ad : g[i]){
    		if(dfa[i] == ad){
    			compo.pb({lup[i], rup[i]});
			}
			else{
				compo.pb({l0[ad], r0[ad]});
			}
		}
		rep(j,compo.size()){
			if(compo[j][1] > i && compo[j][1] < n - 1){
				ans.pb({compo[j][1], compo[j][1] + 1});
				cnt++;coin++;
			}
		}
		rep(j,compo.size()){
			if(compo[j][1] < i && compo[j][0] > 0 && compo[j][0] < i){
				ans.pb({compo[j][0], compo[j][0] - 1});
				cnt++;coin++;
			}
		}
		ll mn = inf;
		rep(j,compo.size()){
			if(compo[j][1] > i && compo[j][0] < i){
				mn = min(mn, compo[j][0]);
			}
		}
		if(mn != inf && mn != 0){
			ans.pb({mn, mn - 1});
			cnt++;
			coin++;
		}
		if(cnt != compo.size() - 1){
			ans.pb({i - 1, i + 1});
			cnt++;
			coin+=2;
		}
		
		csp(coin);cend(cnt);
		rep(i,ans.size()){
			csp(ans[i][0] + 1);cend(ans[i][1] + 1);
		}
		cendl;
	}
		    
}
 
int main(){
//	ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);

    cin>>tt;
	for(ttt = 1;ttt <= tt;ttt++){
		sol();
	}
	return 0;
}
