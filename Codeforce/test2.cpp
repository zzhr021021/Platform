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

const ll N = 200500;
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

const ll NN = 1110;

bool inv(ll x, vll & v){
	for(auto o : v){
		if(o == x)return true;
	}
	return false;
}

ll get_cnt(vi & v, ll x, ll y){
	if(v.size() == 0)return 0;
	if(v.back() < x)return 0;
	if(v.front() > y)return 0;
	ll l, r;
	ll retl, retr;
	l = 0, r = v.size() - 1;
	while(l != r){
		ll mid = (l + r) / 2;
		if(v[mid] >= x){
			r = mid;
		}
		else{
			l = mid + 1;
		}
	}
	retl = l;
	l = 0, r = v.size() - 1;
	while(l != r){
		ll mid = (l + r + 1) / 2;
		if(v[mid] <= y){
			l = mid;
		}
		else{
			r = mid - 1;
		}
	}
	retr = l;
	return retr - retl + 1;
}

map<ll, ll> gcnt;
unordered_map<ll, vi, custom_hash> sls;

void sol()
{
	gcnt.clear();
	sls.clear();
	cin>>n>>q;
	rep1n(i,n){
		cin>>a[i];
	}
	vll more;
	rep1n(i,n){
		gcnt[a[i]]++;
	}
	for(auto o : gcnt){
		sls[o.first] = vi();
	}
	rep1n(i,n){
		sls[a[i]].push_back(i);
	}

	set<ll> outv;
	rep(i,q){
		outv.clear();
		cin>>x>>y;
		rep(ii,45){
			ll pos = rnd() % (y - x + 1) + x;
			if(outv.size() == 2)break;
			if(get_cnt(sls[a[pos]], x, y) > (y - x + 1) / 3){
				outv.insert(a[pos]);
			}
		}

		if(outv.size() == 0){
				cend(-1);
		}
		else{
			for(auto o : outv){
				csp(o);
			}
			cendl;
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