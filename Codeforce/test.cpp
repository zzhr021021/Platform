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
// mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

void printvec(vll & v){
	for(ll &x : v){
		cout << x << " ";
	}
	cendl;
}

ll dx[4] = {0, -1, 0, 1};
ll dy[4] = {1, 0, -1, 0};
string enws = "enws";
string enwsupper = "ENWS";
vector<vector<char>> a(25, vector<char>(25));
ll hx, hy, bx, by, tarx, tary;
ll dist_h[25][25][25][25];
ll dist_b[25][25][25][25];
struct node{
	ll hx, hy, bx, by, dist_h, dist_b;
	string path;
};

void sol(){
	cin>>n>>m;
	ll maze = 0;
	while(n){
		maze += 1;
		cout << "Maze #" << maze << endl;
		vector<string> rows(n);
		rep(i,n)cin>>rows[i];
		
		rep(i, n + 2){
			rep(j,m + 2){
				a[i][j] = '#';
				rep(idir, 4){
					dist_b[i][j][idir] = inf;
					dist_h[i][j][idir] = inf;
				}
			}
		}
		rep(i,n){
			rep(j,m){
				a[i + 1][j + 1] = rows[i][j];
			}
		}
		n += 2;m += 2;
		rep(i,n){
			rep(j,m){
				if(a[i][j] == 'S'){
					hx = i;hy = j;a[i][j] = '.';
				}
				if(a[i][j] == 'B'){
					bx = i;by = j;a[i][j] = '.';
				}
				if(a[i][j] == 'T'){
					tarx = i;tary = j;a[i][j] = '.';
				}
			}
		}

		


		cin>>n>>m;
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
