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
ll up[200005][20];
ll snack[200005][20];

map<ll, ll> expo;
ll pow2[60];

ll ti = 0;

void dfs(ll o, ll p_fa, ll p_dep){
	fa[o] = p_fa;
	up[o][0] = p_fa;
	snack[o][0] = (1 << c[o]);
	rep1(i,20){
		ll tp = up[o][i - 1];
		if(tp != -1){
			up[o][i] = up[tp][i - 1];
			snack[o][i] = snack[o][i - 1] | snack[tp][i - 1];
		}
		if(up[o][i] == -1){
			for(int j = i + 1;j < 20;j++){
				snack[o][j] = snack[o][j - 1];
			}
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

bool fun_isfa(ll fa, ll o){
	if(tin[o] > tin[fa] && tout[o] < tout[fa])return true;
	else return false;
}

// make sure it exist
ll fun_getance(ll o, ll dist){
	if(dist > dep[o]){
		return -1;
	}
	while(dist != 0){
		ll tp = dist & (-dist);
		dist -= tp;
		o = up[o][expo[tp]];
	}
	return o;
}

ll fun_LCA(ll u, ll v){
	if(u == v)return u;
	if(dep[v] > dep[u]){
		ll tp = u;
		u = v;
		v = tp;
	}
	u = fun_getance(u, dep[u] - dep[v]);
	ll step = 0;
	while(u != v){
		// ctest;
		// csp(u);cend(v);
		if(up[u][step] == -1){
			step -= 1;
		}
		else if(up[u][step] == up[v][step]){
			ll x = fun_getance(u, pow2[step] - 1);
			ll y = fun_getance(v, pow2[step] - 1);
			if(x != y){
				u = up[u][step];
				v = up[v][step];
				break;
			}
			else{
				step -= 1;
			}
		}
		else{
			u = up[u][step];
			v = up[v][step];
			step += 1;
		}
	}
	return u;
}

ll fun_get_line_snack(ll ance, ll o){
	if(ance == o){
		return snack[o][0];
	}
	ll ret = 0;
	ll sz = dep[o] - dep[ance] + 1;
	while(sz != 0){
		ll tp = sz & (-sz);
		sz -= tp;
		ret = ret | snack[o][expo[tp]];
		o = up[o][expo[tp]];
	}
	return ret;
}

ll fun_get_snack(ll u, ll v){
	ll common = fun_LCA(u, v);
	ll bits = fun_get_line_snack(common, u) | fun_get_line_snack(common, v);
	return __builtin_popcountll(bits);
}

void sol(){
	rep(i,100005){
		rep(j,20){
			up[i][j] = -1;
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
	dfs(1, -1, 0);

	// ctest;
	// rep1n(i,n){
	// 	rep(j,20){
	// 		csp(__builtin_popcountll(snack[i][j]));;
	// 	}
	// 	cendl;
	// }

	rep(i,q){
		cin>>x>>y;
		cend(fun_get_snack(x, y));
	}
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	for(int i = 0, j = 1;i < 30;i++, j *= 2){
		expo[j] = i;
		pow2[i] = j;
	}

	tt = 1;
//	cin>>tt;
	for(ttt = 1;ttt <= tt;ttt++){
		sol();
	}
	system("pause");
	return 0;
}
