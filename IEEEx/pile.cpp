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

ll a[500500];
ll b[200500];

ll md(ll x, ll p)
{
	return (x % p + p) % p;
}

void sol(){
	rep1n(i,4){
		cin>>a[i]>>b[i];
	}
	ll ans = 0;
	for(ll i = a[1];i <= b[1];i++){
		for(ll j = b[2];j <= b[2];j++){
			for(ll ii = a[3];ii <= b[3];ii++){
				for(ll jj = a[4];jj <= b[4];jj++){
					if((i ^ j ^ ii ^ jj) == 0){
						
					}
				}
			}
		}
	}
	cend(ans);
}

int main(){

	// ios_base::sync_with_stdio(false);
	// cin.tie(nullptr);
	// cout.tie(nullptr);

	tt = 1;
	cin >> tt;
	for (ttt = 1; ttt <= tt; ttt++)
	{
		sol();
	}
	system("pause");
	return 0;
}