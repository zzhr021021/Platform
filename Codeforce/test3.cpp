#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)

#define ll long long
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>

#define csp(n) cout << n << " "
#define cend(n) cout << n << endl
#define cendl cout << endl
#define ctest cout << "test   "
#define pb push_back

const ll MOD = 1e9;
ll p = MOD;
const ll inf = 1e18;
using namespace std;
 
ll tt;
ll ttt;
ll n,k,m,d,q,t,x,y,z,h;

ll dist[1500][150];
ll vis[1500][150];
vector<pll> g[1500];
ll c[1500];
struct node{
	ll dist, city, fuel;
};
bool operator<(const node & u, const node & v){
	return u.dist > v.dist;
}

void sol(){
	cin>>n>>m;
	rep(i,n)cin>>c[i];
	rep(i,m){
		cin>>x>>y>>z;
		g[x].pb({y, z});
		g[y].pb({x, z});
	}
	cin>>q;
	rep(i,q){
		memset(dist, 0x3f, sizeof(dist));
		memset(vis, 0, sizeof(vis));
		cin>>z>>x>>y;
		dist[x][0] = 0;

		priority_queue<node> pq;
		pq.push({0, x, 0});
		while(pq.size()){
			auto o = pq.top();
			pq.pop();
			ll odist = o.dist;
			ll ocity = o.city;
			ll ofuel = o.fuel;
			if(vis[ocity][ofuel])continue;
			vis[ocity][ofuel] += 1;
			if(ofuel < z){
				if(odist + c[ocity] < dist[ocity][ofuel + 1]){
					dist[ocity][ofuel + 1] = odist + c[ocity];
					pq.push({odist + c[ocity], ocity, ofuel + 1});
				}
				for(auto ad : g[ocity]){
					ll city = ad.first;
					ll cost = ad.second;
					if(ofuel >= cost){
						if(odist < dist[city][ofuel - cost]){
							dist[city][ofuel - cost] = odist;
							pq.push({odist, city, ofuel - cost});
						}
					}
				}
			}
		}
		ll ans = MOD;
		for(int i = 0;i <= z;i++){
			ans = min(ans, dist[y][i]);
		}
		if(ans >= MOD){
			cend("impossible");
		}
		else{
			cend(ans);
		}
	}
	
}

int main(){
	tt = 1;
	sol();
	system("pause");
	return 0;
}