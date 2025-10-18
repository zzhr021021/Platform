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
#define smpq priority_queue<long long, vector<long long>, greater<long long>>
#define bgpq priority_queue<long long>

#define yes cout << "YES\n"
#define no cout << "NO\n"
#define csp(n) cout << n << " "
#define cend(n) cout << n << endl
#define cendl cout << endl
#define ctest cout << "test   "
#define cgap cout << "--------------------" << endl
#define pb push_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

#define alice cout << "Alice\n"
#define bob cout << "Bob\n"
#define draw cout << "Draw\n"

const ll MOD = 1e9 + 7;
const ll MODD = 1e9 + 9;
const ll MOOD = 998244353;
ll p = MOOD;
const ll inf = 1e18;
const ll INF = 1e18;
const ll N = 200500;
// ll dix[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
// ll diy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
using namespace std;
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM =
            std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

void ckmax(ll &x, ll y)
{
	if (y > x)
		x = y;
}
void ckmin(ll &x, ll y)
{
	if (y < x)
		x = y;
}
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

const ll NN = 800;

bool inv(ll x, vll & v){
	for(auto o : v){
		if(o == x)return true;
	}
	return false;
}

void sol()
{
	cin>>n>>q;
	set<ll> st;
	rep1n(i,n){
		cin>>a[i];
		st.insert(a[i]);
	}
	map<ll, ll> gcnt;
	vll more;
	unordered_map<ll, vi> pre;
	rep1n(i,n){
		gcnt[a[i]]++;
	}
	for(auto o : gcnt){
		if(o.second >= NN / 3){
			more.push_back(o.first);
			pre[o.first] = vector<int>(N + 5, 0);
			rep1n(i,n){
				pre[o.first][i] = pre[o.first][i - 1];
				if(a[i] == o.first){
					pre[o.first][i]++;
				}
			}
		}
	}
	rep(i,q){
		vll outv;
		cin>>x>>y;
		if(y - x + 1 <= NN){
			unordered_map<ll, ll> cnt;
			for(int i = x;i <= y;i++){
				cnt[a[i]]++;
				if(cnt[a[i]] > (y - x + 1) / 3){
					if(!inv(a[i], outv)){
						outv.push_back(a[i]);
					}
				}
			}
		}
		else{
			for(auto o : more){
				if(pre[o][y] - pre[o][x - 1] > (y - x + 1) / 3){
					outv.push_back(o);
				}
			}
		}
		if(outv.size() == 0){
				cend(-1);
		}
		else if(outv.size() == 1){
			cend(outv[0]);
		}
		else{
			csp(min(outv[0], outv[1]));
			cend(max(outv[0], outv[1]));
		}
	}
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