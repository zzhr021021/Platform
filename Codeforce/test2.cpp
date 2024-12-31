#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (ll i = 1; i <= (n); ++i)
#define rep1nr(i, n) for (int i = (n); i >= 1; --i)
#define rep01n(i, n) for (int i = 0; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define replr(i, l, r) for (int i = l;i <= r;i++)

#define ll long long
#define ull unsigned long long
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define vb vector<bool>
#define csp(n) cout << n << " "
#define cend(n) cout << n << endl
#define cendl cout << endl
#define ctest cout << "test   "
#define pb push_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
 
const ll MOD = 1e9 + 7;
const ll MODD = 1e9 + 9;
const ll MOOD = 998244353;
ll p = MOOD;
const ll inf = 1e18;
const ll N = 1e6;
using namespace std;

ll tt, ttt;
ll n,k,m,t,x,y,z,h,r;

ll a[300];
ll b[300];
const ll offset = 450;
ll dp[25][900];
pll fa[220][25][900];

void outpt(ll n, ll m, ll dif){
	if(n < 0)return;
	if(m < 0 || dif < 0)return;
	outpt(n - 1, fa[n][m][dif].first, fa[n][m][dif].second);
	if(fa[n][m][dif].first != m && n != 0){
		cout << " ";cout << n;
	}
}

void sol(){
	ll testcase = 0;
	while(cin>>n>>m && n){
		testcase += 1;
		rep1n(i,n)cin>>a[i]>>b[i];
		memset(dp, -0x3f, sizeof(dp));
		dp[0][offset] = 0;
		fa[0][0][offset] = {-1, -1};

		rep1n(i,n){
			rep1nr(j,m){
				for(int k = -400;k <= 400;k++){
					ll tp = offset + k - (a[i] - b[i]);
					if(tp < offset - 400 || tp > offset + 400)continue;
					if(dp[j - 1][offset + k - (a[i] - b[i])] + (a[i] + b[i]) > dp[j][offset + k]){
						dp[j][offset + k] = dp[j - 1][offset + k - (a[i] - b[i])] + (a[i] + b[i]);
						fa[i][j][offset + k] = {j - 1, offset + k - (a[i] - b[i])};
					}
					else{
						fa[i][j][offset + k] = {j, offset + k};
					}
				}
			}
		}
		ll ansind = inf;
		ll anssm = -1;
		ll ansdif = 0;
		for(int i = 0;i <= 400;i++){
			bool flag = false;
			if(dp[m][offset + i] >= 0){
				if(dp[m][offset + i] > anssm){
					anssm = dp[m][offset + i];
					ansind = offset + i;
				}
				flag = true;
			}
			if(dp[m][offset - i] >= 0){
				if(dp[m][offset - i] > anssm){
					anssm = dp[m][offset - i];
					ansind = offset - i;
				}
				flag = true;
			}
			if(flag)break;
		}
		ansdif = ansind - offset;
		cout << "Jury #" << testcase << endl;
		cout << "Best jury has value ";csp((anssm + ansdif) / 2);
		cout << "for prosecution and value ";csp((anssm - ansdif) / 2);
		cout << "for defence: " << endl;
		outpt(n, m, ansind);
		cendl;
	}
	
}

int main(){
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	while (cin >> n >> m, n || m)
        solve();
	return 0;
}
