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
#define ctest cout << "test   "
 
#define alice cout<<"Alice\n"
#define bob cout<<"Bob\n"
#define draw cout<<"Draw\n"

#define pb push_back
 
typedef long long int ll;
const ll MOD = 998244353;
ll p = MOD;
const ll inf = 1e18;
const int N = 3e5+5;
using namespace std;
 
ll tt;
ll ttt;
ll n,k,m,x,y,d,q,f,h,w,t,R;

ll l[N];
ll s[N];
ll dist[N];
bool vis[N];
vector<pair<ll, ll>> g[N];

ll last[N]; 

void c1ton(){
	if(last[n] == n){
		cend(-1);return;
	}
	vector<ll> ans;
	ans.pb(n);
	ll tp = last[n];
//	ctest;csp(n);cend(tp);
	while(tp != 1){
		ans.pb(tp);
		tp = last[tp];
	}
	ans.pb(1);
	ll kk = ans.size();
	repr(i,kk){
		csp(ans[i]);
	}
}

// input: 
// n: number of vertex
// m: number of edge
// next m line: each line a triple, v1,v2,dis
// 5 6
// 1 2 2
// 1 3 8
// 2 3 1
// 3 4 2
// 4 5 2
// 2 5 10
void sol(){
	cin>>n>>m;
	rep1n(i,n)last[i] = i;
	rep1n(i,n)g[i].clear();
	rep(i,m){
		cin>>x>>y>>d;
		g[x].push_back({y,d});
		g[y].push_back({x,d});
	}
	set<pair<ll, ll>> st;
	st.insert({0, 1});
	for(int i = 1;i <= n;i++){
		vis[i] = false;
		dist[i] = inf;
	}
	dist[1] = 0;
	while(!st.empty()){
		auto sp = *st.begin();
		ll ct, co;// current distance(time), and which vertex
		ct = sp.first;
		co = sp.second;
		if(vis[co]){
			st.erase(sp);
		}
		else{
			st.erase(sp);
			vis[co] = true;
			for(auto ad_pa : g[co]){
				ll ad = ad_pa.first;
				ll td = ad_pa.second;
				if(vis[ad])continue;
				if(ct + td < dist[ad]){
					st.erase({dist[ad], ad});
					last[ad] = co;
					dist[ad] = ct + td;
					st.insert({dist[ad], ad});
				}
			}
		}
	}
	// ans: 0 2 3 5 7
	rep1n(i,n){
		csp(dist[i]);
	}
	
	c1ton();
	cendl;
	
}
 
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    tt = 1;
	for(ttt = 1;ttt <= tt;ttt++){
		sol();
	}
	return 0;
}
