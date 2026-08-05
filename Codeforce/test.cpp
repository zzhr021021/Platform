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
const ll MOOD = 676767677;
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

ll a[200050];
ll b[200050];

void md(ll & x){
    x = (x + p) % p;
}

ll ladder(ll x){
    return (1 + x) * x / 2;
}
ll sq(ll x){
    return x * x;
}
ll qpow(ll x, ll y){
    ll ans = 1;
    while(y){
        if(y&1) ans = ans * x % p;
        x = x * x % p,y>>=1;
    }
    return ans;
}

vll mat[100500];
ll rsm[100500];
ll csm[100500];

ll calct(ll need, ll val){
    // calc the number of ops need to be done, make sure need > 0
    if(need <= 0)return 0;
    return (need + val - 1) / val;
}

void sol(){
    cin>>n>>m>>k;
    if(m == 1){
        swap(n, m);
    }
    rep(i,n + 5)rsm[i] = 0;
    rep(j,m + 5)csm[i] = 0;
    rep1n(i,n){
        mat[i].resize(m + 5);
        rep1n(j,m){
            cin>>mat[i][j];
            rsm[i] += mat[i][j];
            csm[j] += mat[i][j];
        }
    }
    
    if(n == 1 && m == 1){
        if(mat[1][1] < 0){
            cend(-1);
        }
        else{
            cend(0);
        }
        return;
    }
    ll ans = inf;
    // calc all mat
    vll needs;
    rep1n(i,n){
        rep1n(j,m){
            ll to = rsm[i] + csm[j] - 3 * mat[i][j];
            times = calct(to, n + m - 3);
            needs.push_back(times);
        }
    }
    sort(all(needs));
    ckmin(ans, needs[k - 1]);
    if(n >= 2 && m >= 2){
        cend(ans);return;
    }
    // use [1, n] and [2, n]
    // [1, n] ' s sub condition : n - 2 , n - 2, ... , n - 2
    // [2, n] ' s sub condition : n - 1, n - 3, ... n - 3, 
    // then mat11 is chosen, and needs[k - 1] in right is chosen

    // two number : x1 and x2, 
    // op1 makes x1 sub z, x2 sub z;
    // op2 makes x1 sub z + 1, x2 sub z - 1
    // do op1 and op2 some times, question : min total ops makes x1 x2 both less or equal than 0
    if(k == 1){
        ckmin(ans, calct(mat[1][1], m - 1));
        ckmin(ans, calct(mat[1][n], m - 1));
    }
    else{
        
    }
    cend(ans);

    
}


ll tnt(){
    while(1){
    }
    return 0;
}


int main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);

    tt = 1;
    cin>>tt;
    for(ttt = 1;ttt <= tt;ttt++){
        sol();
    }
    system("pause");
    return 0;
}