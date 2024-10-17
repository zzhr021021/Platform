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
ll dx[4] = {-1, -1, 1, 1};
ll dy[4] = {1, -1, -1, 1};
using namespace std;
 
ll tt;
ll ttt;
ll n,k,m,d,q,t,x,y,z,h;
// mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

void printvec(vll & v){
	for(ll &x : v){
		cout << x << " ";
	}
	cendl;
}

ll g[300000][4];
bool vis[300000];
bool ext[300000];
ll dist[300000];
struct node{
	ll id, dist;
};

void sol(){
	
	cin>>n>>m;

	ll nodecnt = (n + 1) * (m + 1);
	rep(i,(n * 5) * (m * 5)){
		rep(idir, 4){
			g[i][idir] = inf;
		}
		vis[i] = ext[i] = false;
		dist[i] = inf;
	}
	vector<string> rows(n);

	rep(i,n)cin>>rows[i];

	if((n + m) % 2 == 1){
		cend("NO SOLUTION");
	}
	else{
		ll nodecnt = (n + 1) * (m + 1);
		rep(i,n){
			rep(j,m){
				if(rows[i][j] == '/'){
					x = (i * (m + 1)) + j + 1;
					y = (i * (m + 1)) + j + m + 1;
					g[y][0] = 0;
					g[x][2] = 0;
					x = (i * (m + 1)) + j;
					y = (i * (m + 1)) + j + m + 1 + 1;
					g[x][3] = 1;
					g[y][1] = 1;
				}
				else{
					x = (i * (m + 1)) + j + 1;
					y = (i * (m + 1)) + j + m + 1;
					g[y][0] = 1;
					g[x][2] = 1;
					x = (i * (m + 1)) + j;
					y = (i * (m + 1)) + j + m + 1 + 1;
					g[x][3] = 0;
					g[y][1] = 0;
				}
			}
		}


		deque<node> nodeq;
		nodeq.push_back({0, 0});
		vis[0] = true;
		dist[0] = 0;
		while(nodeq.size()){
			auto o = nodeq.front();
			// ctest;csp(o.id + 1);cend(o.dist);
			nodeq.pop_front();
			ll id = o.id;
			x = id / (m + 1);
			y = id % (m + 1);
			if(ext[id])continue;
			ext[id] = true;
			rep(idir, 4){
				ll nx = x + dx[idir];
				ll ny = y + dy[idir];
				ll nid = nx * (m + 1) + ny;
				// csp("sub");
				// csp(nx);csp(ny);cend(nid);
				if(nx >= 0 && ny >= 0 && nx < n + 1 && ny < m + 1 && !ext[nid]){
					// csp("truesub");
					// cend(nid);
					if(g[id][idir] == 0){
						// cend(nid);
						vis[nid] = true;
						if(o.dist < dist[nid]){
							dist[nid] = o.dist;
							node u = {nid, o.dist};
							nodeq.push_front(u);
						}
					}
					else if(g[id][idir] == 1){
						vis[nid] = true;
						if(o.dist + 1 < dist[nid]){
							dist[nid] = o.dist + 1;
							node u = {nid, o.dist + 1};
							nodeq.push_back(u);
						}
					}
				}
			}
		}
		cend(dist[nodecnt - 1]);

	}

}


int main(){
	// ios_base::sync_with_stdio(false);
	// cin.tie(nullptr);
	// cout.tie(nullptr);

	tt = 1;
	// cin>>tt;
	for(ttt = 1;ttt <= tt;ttt++){
		sol();
	}
	system("pause");
	return 0;
}