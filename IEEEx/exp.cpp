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

#define ll long long
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

const ll MOD = 1e9 + 7;
const ll MODD = 1e9 + 9;
const ll MOOD = 998244353;
ll p = MOOD;
const ll inf = 1e18;
const ll N = 200500;
using namespace std;

void printvec(vll &v)
{
	for (auto o : v)
	{
		csp(o);
	}
	cendl;
}
ll tt, ttt;
ll n, k, m, t, x, y, z, h, q, d, s;

ll a[200500];
ll b[200500];

ll md(ll x, ll p)
{
	return (x % p + p) % p;
}

bool rec[2000];
double dp[2000];
double dpn[2000];

double spow(double x, ll po){
	double ret = 1;
	rep(ip,po){
		ret *= x;
	}
	return ret;
}

void sol(){
	cin>>n>>k;
	rep(i,n){
		cin>>x;
		rec[x] = true;
	}
	dp[0] = 1;
	rep(i,1024){
		if(rec[i]){
			rep(j,1024){
				dpn[j] = dp[j] / 2;
			}
			rep(j,1024){
				dpn[(j ^ i)] += dp[j] / 2;
			}
			rep(j,1024){
				dp[j] = dpn[j];
			}
		}
	}
	double ans = 0;
	rep(i,1024){
		ans += spow(i, k) * dp[i];
	}
	cout << setprecision(2) << fixed <<ans;

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