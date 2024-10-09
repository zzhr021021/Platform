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

ll ans ;
ll stk[1000];
struct DLX{
	static const int MAXSIZE = 1e5 + 10;
	int n, m, tot, first[MAXSIZE + 10], siz[MAXSIZE + 10];
	int L[MAXSIZE + 10], R[MAXSIZE + 10], U[MAXSIZE + 10], D[MAXSIZE + 10];
	int col[MAXSIZE + 10], row[MAXSIZE + 10];
	
	void build(const int &r, const int &c) {
		n = r, m = c;
		for (int i = 0; i <= c; ++i) {
			L[i] = i - 1, R[i] = i + 1;
			U[i] = D[i] = i;
		}
		L[0] = c, R[c] = 0, tot = c;
		memset(first, 0, sizeof(first));
		memset(siz, 0, sizeof(siz));
	}
	
	void insert(const int &r, const int &c) {
		col[++tot] = c, row[tot] = r, ++siz[c];
		D[tot] = D[c], U[D[c]] = tot, U[tot] = c, D[c] = tot;
		if (!first[r])
			first[r] = L[tot] = R[tot] = tot;
		else {
			R[tot] = R[first[r]], L[R[first[r]]] = tot;
			L[tot] = first[r], R[first[r]] = tot;
		}
	}
	
	void remove(const int &c) {
		int i, j;
		L[R[c]] = L[c], R[L[c]] = R[c];
		for (i = D[c]; i != c; i = D[i])
		for (j = R[i]; j != i; j = R[j])
		U[D[j]] = U[j], D[U[j]] = D[j], --siz[col[j]];
	}
	
	void recover(const int &c) {
		int i, j;
		for (i = U[c]; i != c; i = U[i])
		for (j = L[i]; j != i; j = L[j]) U[D[j]] = D[U[j]] = j, ++siz[col[j]];
		L[R[c]] = R[L[c]] = c;
	}
	
	bool dance(int dep) {
		if (!R[0]) {
			ans = dep;
			return 1;
		}
		int i, j, c = R[0];
		for (i = R[0]; i != 0; i = R[i])if (siz[i] < siz[c]) c = i;
		remove(c);
		for (i = D[c]; i != c; i = D[i]) {
			stk[dep] = row[i];
			for (j = R[i]; j != i; j = R[j]) remove(col[j]);
			if (dance(dep + 1)) return 1;
			for (j = L[i]; j != i; j = L[j]) recover(col[j]);
		}
		recover(c);
		return 0;
	}
}solver;


void sol(){
	cin>>n>>m;
	solver.build(n, m);
	rep1n(i,n){
		rep1n(j,m){
			cin>>x;
			if(x){
				solver.insert(i, j);
			}
		}
	}
	
	solver.dance(1);
	
	if(ans){
		for (int i = 1; i < ans; ++i) cout << stk[i] << ' ';
	}
	else{
		cend("No Solution!");
	}
	
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
//	system("pause");
	return 0;
}
