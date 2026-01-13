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

ll a[200500];
ll dp[200500][450];
ll dps[200500][450];
// use for slp[b + 1 ~ n][1 - b]
ll slp[200500][450];
ll slpsm[200500][450];
ll slpld[200500][450];
ll ans[200500];

// ll rdp[200500][450];
 
void sol(){
    cin>>n;
	
	// real
	// ll tp[9];
	// for(int i = 0;i < (ll)81 * 81 * 81 * 81;i++){
	// 	if(i % 500000 == 0){
	// 		ctest;csp("i   ");cend(i);
	// 	}
	// 	ll ti = i;
	// 	rep1n(ip, n){
	// 		tp[ip] = ti % 9;
	// 		ti /= 9;
	// 	}
	// 	if(tp[1] == 0)continue;
	// 	bool des = false;
	// 	bool can = true;
	// 	ll n0 = 0;
	// 	ll sum = 0;
	// 	for(int j = 1;j <= 7;j++){
	// 		if(tp[j] != 0){
	// 			n0++;
	// 			sum += tp[j];
	// 		}
	// 		if(tp[j] > tp[j + 1]){
	// 			des = true;
	// 		}
	// 		if(tp[j] < tp[j + 1]){
	// 			if(des){
	// 				can = false;
	// 				break;
	// 			}
	// 		}
	// 	}
	// 	if(can){
	// 		if(tp[8]){
	// 			n0++;
	// 			sum += tp[8];
	// 		}
	// 		rdp[sum][n0]++;
	// 	}
	// }
	// ctest;
	// cendl;
	// rep1n(i,n){
	// 	rep1n(j,n){
	// 		csp(rdp[i][j]);
	// 	}
	// 	cendl;
	// }
	// cendl;

	ll b = (ll)sqrt(n);
	// dp & dps
	rep1n(j,b){
		for(int i = 1;i <= n;i++){
			if(i + j == 2){
				dp[i][j] = 1;
			}
			else if(i >= j){
				dp[i][j] = dp[i - 1][j - 1] + dps[i - j][j];
			}
			dps[i][j] = dps[i][j - 1] + dp[i][j];
		}
	}
	// (i, b)
	for(int i = 1;i <= n;i++){
		for(int l = b;l >= 0;l--){
			if(i - l >= b + 1){
				// [i - 1][j - 1]
				slp[i][l] = dp[i - 1][b - 1];
				ctest;csp(i);csp(l);csp(slp[i][l]);
				if(i - l - 1 >= 0){
					slp[i][l] += slp[i - l - 1][l];
				}
				cend(slp[i][l]);
				// slpsm
				if(i - b >= 1){
					slp[i][l] += slpld[i - b][l + 1];
				}
			}
			else{
				slp[i][l] = dp[i][b];
			}
			// slpsm
			slpsm[i][l] = slp[i][l];
			if(i - l >= 1){
				slpsm[i][l] += slpsm[i - l][l];
			}
			// slpld
			slpld[i][l] = slpsm[i][l] + dps[i][b - 1];
			if(i - l >= 1){
				slpld[i][l] += slpld[i - l][l];
			}
		}
	}
	ctest;cendl;
	rep1n(i,8){
		rep1n(j,8){
			csp(slp[i][j]);
		}
		cendl;
	}
	cendl;
	rep1n(i,8){
		rep1n(j,8){
			csp(slpsm[i][j]);
		}
		cendl;
	}
	cendl;
	rep1n(i,8){
		rep1n(j,8){
			csp(slpld[i][j]);
		}
		cendl;
	}
	cendl;

	cend("ans");
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