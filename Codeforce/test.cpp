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

ll c[200005];
vll g[200005];

ll tin[200005];
ll tout[200005];
ll dep[200005];
ll fa[200005];
ll baians[200005][20];

ll ti = 0;

void dfs(ll o, ll p_fa, ll p_dep){
	fa[o] = p_fa;

	baians[o][0] = p_fa;
	rep1(i,20){
		ll tp = baians[o][i - 1];
		if(tp != -1){
			baians[o][i] = baians[tp][i - 1];
		}
		if(baians[o][i] = -1){
			break;
		}
	}
	
	dep[o] = p_dep;
	ti++;
	tin[o] = ti;

	for(auto ad : g[o]){
		if(ad != p_fa){
			dfs(ad, o, p_dep + 1);
		}
	}

	ti++;
	tout[o] = ti;
}

ll fun_isfa(ll fa, ll o){
	if(tin[o] > tin[fa] && tout[o] < tout[fa])return true;
	else return false;
}

// make sure it exist
ll fun_getans(ll o, ll dist){
	if(dist > dep[o]){
		return -1;
	}
	if(dist == 0){
		return o;
	}
	while(dist != 0){
		
	}
}

ll fun_LCA(ll u, ll v){

}

void sol(){
	rep(i,100005){
		rep(j,20){
			baians[i][j] = -1;
		}
	}
	cin>>n>>q;
	rep1n(i,n){
		cin>>c[i];
	}
	rep(i,n - 1){
		cin>>x>>y;
		g[x].pb(y);
		g[y].pb(x);
	}
	rep(i,q){
		cin>>x>>y;
	}

	dfs(1, -1, 0);

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
