#include <bits/stdc++.h>
#define debug(x) cout << #x << " = " << x << endl
#define vdebug(a)         \
	cout << #a << " = ";  \
	for (auto x : a)      \
		cout << x << " "; \
	cout << "\n";

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (ll i = 1; i <= (n); ++i)
#define rep1nr(i, n) for (int i = (n); i >= 1; --i)
#define rep01n(i, n) for (int i = 0; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define replr(i, l, r) for (int i = l; i <= r; i++)
#define repij(i, j, n, m)         \
	for (int i = 0; i < (n); ++i) \
		for (int j = 0; j < (m); ++j)

#define ll int
#define ull unsigned long long
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define vb vector<bool>
#define vpl vector<pair<long long, long long>>

#define yes cout << "YES\n"
#define no cout << "NO\n"
#define csp(n) cout << n << " "
#define cend(n) cout << n << endl
#define cendl cout << endl
#define ctest cout << "test   "
#define cgap cout << "--------------------" << endl
#define pb push_back
#define all(a) a.begin(), a.end()

const ll inf = 1e9;
const ll INF = 1e9;
const ll N = 200500;
using namespace std;


ll tt, ttt;
ll n, k, m, t, x, y, z, h, q, d, s;
ll a[200500];
ll mat[1000][1000];
ll dp[1050][1050];

void sol(){ 
    cin>>n;
    rep1n(i,n){
        cin>>a[i];
    }
    ll l = 1, r = n / 2;
    while(l != r){
        
    }
    
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	tt = 1;
	// cin >> tt;
	for (ttt = 1; ttt <= tt; ttt++)
	{
		sol();
	}
	system("pause");
	return 0;
}