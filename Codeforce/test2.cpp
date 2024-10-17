#include<iostream>
#include<deque> //头文件啥的就不用我说了吧
#include<cstring>
#include<string>
#include<vector>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define csp(n) cout << n << " "
#define cend(n) cout << n << endl
#define cendl cout << endl
#define ctest cout << "test   "
using namespace std;

const int inf = 1e9 + 7;
const int dx[4] = {-1, -1, 1, 1};
const int dy[4] = {1, -1, -1, 1};
 
int tt;
int n,k,m,t,x,y;

int g[300000][4];
bool ext[300000];
int dist[300000];
struct node{
	int id, dist;
};

void sol(){
	cin>>n>>m;
	vector<string> rows(n);
	rep(i,n)cin>>rows[i];
	int nodecnt = (n + 1) * (m + 1);
	memset(dist, 0x3f, sizeof(dist));
	

	if((n + m) % 2 == 1){
		cend("NO SOLUTION");
	}
	else{
		int nodecnt = (n + 1) * (m + 1);
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
		dist[0] = 0;
		while(nodeq.size()){
			auto o = nodeq.front();
			nodeq.pop_front();
			int id = o.id;
			x = id / (m + 1);
			y = id % (m + 1);
			if(ext[id])continue;
			ext[id] = true;
			rep(idir, 4){
				int nx = x + dx[idir];
				int ny = y + dy[idir];
				int nid = nx * (m + 1) + ny;
				if(nx >= 0 && ny >= 0 && nx < n + 1 && ny < m + 1 && !ext[nid]){
					if(g[id][idir] == 0){
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
	tt = 1;
	sol();
	return 0;
}