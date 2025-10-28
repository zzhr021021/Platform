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

#define ll int
#define ull unsigned long long
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define vb vector<bool>
#define vpl vector<pair<long long, long long>>
#define csp(n) cout << n << " "
#define cend(n) cout << n << endl
#define cendl cout << endl
#define ctest cout << "test   "
#define cgap cout << "--------------------" << endl
#define pb push_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define yes cout << "Yes\n"
#define no cout << "No\n"
const ll N = 200500;
using namespace std;

const ll MOD = 1e9 + 7;
const ll MODD = 1e9 + 9;
const ll MOOD = 998244353;
ll p = MOOD;

ll tt, ttt;
ll n, k, m, t, x, y, z, h, q, d, s;

// 分割数: https://ja.wikipedia.org/wiki/%E5%88%86%E5%89%B2%E6%95%B0
// O(n*sqrt(n))
// assume n <= 200500
// let b = sqrt(n)
ll a[200500];
ll dp[200500][450];

// use for slp[b + 1 ~ n][1 - b]
ll slp[200500][450];

ll ans[200500];
 
void sol(){
    cin>>n;
	
	ll b = (ll)sqrt(n);
	rep1n(j,b){
		for(int i = j;i <= N;i++){
			if(i + j == 2){
				dp[i][j] = 1;
			}
			else{
				dp[i][j] = dp[i - 1][j - 1] + dp[i - j][j];
			}
			if(j != b){
				ans[i] += dp[i][j];
			}
		}
	}
	// (i, b)
	for(int i = b;i <= n;i++){
		for(int l = b;l >= 0;l--){
			if(i - l >= b + 1){
				slp[i][l] = dp[i - 1][b - 1];
				if(i - l - 1 >= 0){
					slp[i][l] += slp[i - l - 1][l];
				}
				if(i - b >= 0){
					if(l + 1 > b){
						slp[i][l] += dp[i - b][b];
					}
					else{
						slp[i][l] += slp[i - b][l + 1];
					}
				}
			}
			else{
				slp[i][l] = dp[i][b];
			}
		}
	}
	for(int i = b;i <= n;i++){
		ans[i] += slp[i][0];
	}

	rep1n(i,n){
		csp(ans[i]);
	}
	cendl;
}

int main(){
	// ios_base::sync_with_stdio(false);
	// cin.tie(nullptr);
	// cout.tie(nullptr);

	tt = 1;
	// cin >> tt;
	for (ttt = 1; ttt <= tt; ttt++)
	{
		sol();
	}
	system("pause");
	return 0;
}