#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (ll i = 1; i <= (n); ++i)
#define rep1nr(i, n) for (int i = (n); i >= 1; --i)
#define rep01n(i, n) for (int i = 0; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define replr(i, l, r) for (int i = l;i <= r;i++)

#define ll int
#define vi vector<int>
#define vll vector<long long>

#define csp(n) cout << n << " "
#define cend(n) cout << n << endl
#define cendl cout << endl
#define ctest cout << "test   "
#define pb push_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

const ll MOD = 1e9 + 7;
const ll inf = 1e9;
const ll N = 1e6;
using namespace std;

ll tt, ttt;
ll n,k,m,t,x,y,z,h,r;

struct person{
	ll g, ind;
}persons[50];
bool cmp(const person & u, const person & v){
	return u.g > v.g;
}
ll dp[35][5050];
ll a[50];
ll sm[50];
ll anss[50];
ll get_range(ll l, ll r){
	return sm[r] - sm[l - 1];
}

void sol(){
	cin>>n>>m;
	rep1n(i,n){
		cin>>a[i];
		persons[i] = {a[i], i};
	}
	sort(persons + 1, persons + 1 + n, cmp);
	rep1n(i,n){
		sm[i] = sm[i - 1] + persons[i].g;
	}

	memset(dp, 0x3f, sizeof(dp));
	rep1n(i,n){
		dp[i][0] = 0;
	}
	rep1n(i,n){
		rep1n(j,m){
			if(j < i)continue;
			dp[i][j] = min(dp[i][j], dp[i][j - i]);
			for(int u = 1;u <= i - 1;u++){
				dp[i][j] = min(dp[i][j], dp[u][j - i] + get_range(u + 1, i) * u);
			}
			// ctest;csp(i);csp(j);csp(dp[i][j]);cendl;
		}
	}
	cend(dp[n][m]);

	

}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	tt = 1;
	// cin>>tt;
	for(ttt = 1;ttt <= tt;ttt++){
		sol();
	}
	system("pause");
	return 0;
}
