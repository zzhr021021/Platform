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
#define vstr vector<string>
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
// ll dix[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
// ll diy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
using namespace std;
// mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

ll tt, ttt;
ll n,k,m,d,t,x,y,z,h,q;

void printvec(vll & v){
	for(ll &x : v){
		cout << x << " ";
	}
	cendl;
}

double a[20][20];
double mat[20][20];

void fiddle(ll st){
	if(st == n)return;
	ll pos = st;
	for(int i = st;i < n;i++){
		if(mat[i][st] != 0){
			pos = i;
			break;
		}
	}
	if(pos != st){
		rep(ij, n + 1){
			swap(mat[st][ij], mat[pos][ij]);
		}
	}
	double inv = 1 / mat[st][st];
	rep(ij, n + 1){
		mat[st][ij] *= inv;
	}
	for(int i = st + 1;i < n;i++){
		double tp = mat[i][st];
		mat[i][st] = 0;
		for(int j = st + 1;j < n + 1;j++){
			mat[i][j] -= tp * mat[st][j];
		}
	}
	fiddle(st + 1);
}
void idlize(){
	for(int i = n;i >= 0;i--){
		for(int j = i + 1;j < n;j++){
			if(mat[i][j] != 0){
				mat[i][n] -= mat[j][n] * mat[i][j];
				mat[i][j] = 0;
			}
		}
	}
}


void sol(){
	cin>>n;
	rep(i,n + 1){
		rep(j,n){
			cin>>a[i][j];
		}
	}
	rep(i,n){
		rep(j,n){
			mat[i][j] = 2 * (a[i + 1][j] - a[i][j]);
			mat[i][n] += a[i + 1][j] * a[i + 1][j] - a[i][j] * a[i][j];
		}
	}
	fiddle(0);
	idlize();
	rep(i,n){
		cout << setprecision(3) << fixed << mat[i][n] << " ";
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