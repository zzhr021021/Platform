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
#define vstr vector<string>

#define csp(n) cout << n << " "
#define cend(n) cout << n << endl
#define cendl cout << endl
#define ctest cout << "test   "
#define cgap cout << "--------------------" << endl
#define pb push_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

const ll inf = 1e18;
const ll INF = 1e18;
const ll N = 200500;
using namespace std;
ll tt, ttt;
ll n, k, m, t, x, y, z, h, q, d, s;

ll a[200500];
ll b[200500];
// Misra-Gries Algorithm
// given vector a, integer k, find all element that have count more than n / k.
// Approximate algorithm, the required element is contained in return for sure, but not all elements in return is needed.
vll misra_gries(vll & a, ll k){
	ll n = a.size();
	map<ll, ll> cnt;
	for(auto o : a){
		if(cnt.count(o)){
			cnt[o]++;
		}
		else if(cnt.size() < k - 1){
			cnt[o] = 1;
		}
		else{
			vll toerase;
			for(auto pa : cnt){
				cnt[pa.first] -= 1;
				if(cnt[pa.first] == 0){
					toerase.push_back(pa.first);
				}
			}
			for(auto o : toerase){
				cnt.erase(o);
			}
		}
	}
	vll ret;
	for(auto o : cnt){
		ret.push_back(o.first);
	}
	return ret;
}
// test case :  7 8 2 2 2 3 3 3 4 4 5 5 6 6 77 77 7 7 7 8 
void sol()
{
	cin>>n>>k;
	csp("find more than ");cend(n / k);
	vll ve;
	rep(i,n){
		cin>>a[i];
		ve.push_back(a[i]);
	}

	auto rve = misra_gries(ve, k);
	for(auto o : rve){
		ctest;csp(o);
	}
	cendl;
	
	
}

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	tt = 1;
	cin >> tt;
	for (ttt = 1; ttt <= tt; ttt++)
	{
		sol();
	}
	system("pause");
	return 0;
}