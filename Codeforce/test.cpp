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
ll dix[4] = {0, -1, 0, 1};
ll diy[4] = {1, 0, -1, 0};
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

struct node{
	ll dist, x, y;
};
char a[900][900];
ll dista[900][900];
ll distb[900][900];
ll ax, ay;
ll bx, by;
ll cx, cy;
ll dx, dy;

bool placenotgood(ll i, ll j, ll turn){
	ll d1 = llabs(i - cx) + llabs(j - cy);
	if(d1 <= turn * 2)return true;
	ll d2 = llabs(i - dx) + llabs(j - dy);
	if(d2 <= turn * 2)return true;
	return false;
}
bool placegood(ll i, ll j, ll turn){
	return !placenotgood(i, j, turn);
}
bool inbound(ll i, ll j){
	return i >= 0 && j >= 0 && i < n && j < m && !(a[i][j] == 'X');
}

void sol(){
	cin>>n>>m;
	vector<string> rows(n);
	rep(i,n)cin>>rows[i];
	rep(i,n+2){
		rep(j,m+2){
			a[i][j] = 'X';
		}
	}
	rep(i,n){
		rep(j,m){
			a[i + 1][j + 1] = rows[i][j];
		}
	}
	n += 2;m += 2;

	ll cghost = 0;
	rep(i,n){
		rep(j,m){
			dista[i][j] = distb[i][j] = inf;
			if(a[i][j] == 'M'){
				ax = i;ay = j;
			}
			if(a[i][j] == 'G'){
				bx = i;by = j;
			}
			if(a[i][j] == 'Z'){
				if(cghost == 0){
					cx = i;cy = j;
				}
				else{
					dx = i;dy = j;
				}
				cghost++;
			}
		}
	}

	ll turn = 1;
	queue<node> qa;
	queue<node> qb;
	qa.push({0, ax, ay});
	qb.push({0, bx, by});
	dista[ax][ay] = 0;
	distb[bx][by] = 0;
	bool flag = false;
	while(true){
		if(flag){
			break;
		}
		if(qa.size() + qb.size() == 0){
			break;
		}
		while(qa.size() && qa.front().dist < turn * 3){
			auto o = qa.front();
			qa.pop();
			if(placenotgood(o.x, o.y, turn)){
				continue;
			}
			rep(idir, 4){
				ll nx = o.x + dix[idir];
				ll ny = o.y + diy[idir];
				if(inbound(nx, ny) && placegood(nx, ny, turn)){
					if(dista[nx][ny] == inf){
						dista[nx][ny] = o.dist + 1;
						qa.push({o.dist + 1, nx, ny});
						if(!flag && distb[nx][ny] != inf){
							flag = true;
							cend(turn);
						}
					}
				}
			}
		}
		// girl
		while(qb.size() && qb.front().dist < turn * 1){
			auto o = qb.front();
			qb.pop();
			if(placenotgood(o.x, o.y, turn)){
				continue;
			}
			rep(idir, 4){
				ll nx = o.x + dix[idir];
				ll ny = o.y + diy[idir];
				if(inbound(nx, ny) && placegood(nx, ny, turn)){
					if(distb[nx][ny] == inf){
						distb[nx][ny] = o.dist + 1;
						// csp("girl push");csp(o.dist + 1);csp(nx);csp(ny);cend(turn);
						qb.push({o.dist + 1, nx, ny});
						if(!flag && dista[nx][ny] != inf){
							flag = true;
							cend(turn);
						}
					}
				}
			}
		}

		turn++;
	}
	if(!flag)cend(-1);

}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	tt = 1;
	cin>>tt;
	for(ttt = 1;ttt <= tt;ttt++){
		sol();
	}
	system("pause");
	return 0;
}