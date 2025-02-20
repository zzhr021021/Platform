#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define maxn 1010
using namespace std;

#define ll int

<<<<<<< Updated upstream
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

#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define csp(n) cout << n << " "
#define cend(n) cout << n << endl
#define cendl cout << endl
#define ctest cout << "test   "
#define pb push_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
 
#define alice cout<<"Alice\n"
#define bob cout<<"Bob\n"
#define draw cout<<"Draw\n"


const ll MOD = 1e9 + 7;
const ll MODD = 1e9 + 9;
const ll MOOD = 998244353;
ll p = MOOD;
const ll inf = 1e18;
const ll INF = 1e18;
const ll N = 1e6;
// ll dix[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
// ll diy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
=======
const ll MOD = 1e9 + 7;
ll p = MOD;
const ll N = 1005;
>>>>>>> Stashed changes
using namespace std;
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

void printvec(vll & v){
	for(auto o : v){
		csp(o);
	}
	cendl;
}

ll tt, ttt;
<<<<<<< Updated upstream
ll n,k,m,t,x,y,z,h,r;
ll b;
ll a[4000];
ll ans = 0;
void sol(){
	cin>>n>>b;
	rep1n(i,n)cin>>a[i];
	// not choose seg n
	vll dp1a(n + 5, 0);
	vll dp1b(n + 5, 0);
	vll dp2a(n + 5, 0);
	vll dp2b(n + 5, 0);
	for(int i = 2;i <= n - 1;i++){
		for(int j = 1;j <= b;j++){
			if(j == 1){
				dp1b[j] = dp2b[j] = 0;
			}
			else{
				dp1b[j] = max(dp1a[j - 1] + a[i], dp2a[j - 1]);
				dp2b[j] = max(dp1a[j], dp2a[j]);
			}
			// ctest;csp(i);csp(j);csp(dp1[i][j]);csp(dp2[i][j]);cendl;
		}
		swap(dp1a, dp1b);
		swap(dp2a, dp2b);
	}
	ans = max(ans, dp1a[b]);
	ans = max(ans, dp2a[b]);

	// choose seg n
	rep(i,n + 5){
		dp1a[i] = dp1b[i] = dp2a[i] = dp2b[i] = 0;
	}
	dp1a[0] = -inf;
	dp1a[1] = a[1];
	dp2a[0] = 0;
	dp2a[1] = -inf;
	for(int i = 2;i <= n;i++){
		for(int j = 1;j <= b;j++){
			if(j == 1){
				dp1b[j] = 0;
				dp2b[j] = a[1];
			}
			else{
				dp1b[j] = max(dp1a[j - 1] + a[i], dp2a[j - 1]);
				dp2b[j] = max(dp1a[j], dp2a[j]);
			}
			// ctest;csp(i);csp(j);csp(dp1[i][j]);csp(dp2[i][j]);cendl;
		}
		swap(dp1a, dp1b);
		swap(dp2a, dp2b);
	}
	ans = max(ans, dp1a[b]);
	// ans = max(ans, dp1[n - 1][b]);
	// ans = max(ans, dp2[n - 1][b]);


	cend(ans);
	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	tt = 1;
	cin>>tt;
	for(ttt = 1;ttt <= tt;ttt++){
		sol();
	}
	system("pause");
=======
ll n,k,m,t,x,y;

ll a[2005];
ll b[2005];

ll pa(ll x){
	ll tp = x & (-x);
	return x - tp;
}
ll fenw[1005][1005];
void add(ll pos, ll val, ll ind){
    while (pos < 1005){
        fenw[ind][pos] += val;
        fenw[ind][pos] = (fenw[ind][pos] % MOD + MOD) % MOD;
        pos |= (pos + 1);
    }
}
ll get(ll pos, ll ind){
    ll res = 0;
    while (pos >= 0){
        res += fenw[ind][pos];
        res %= MOD;
        pos &= (pos + 1);
        pos--;
    }
    return res;
}

ll ve[2000];

int main(){
	tt = 1;
	scanf("%d", &tt);
	for(ttt = 1;ttt <= tt;ttt++){
		ll ans = 0;
		scanf("%d", &n);
		scanf("%d", &m);
		for(int i = 1;i <= n;i++){
			scanf("%d", &a[i]);
			b[i] = a[i];
		}
		sort(b+1, b+n+1);
		int nn=unique(b+1, b+n+1)-(b+1);
		for (int i=1; i<=n; i++) a[i]=lower_bound(b+1, b+n+1, a[i])-b; // ??? 
		
		memset(fenw, 0, sizeof(fenw));
			
		add(0, 1, 0);
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= m;j++){
				ve[j] = get(a[i] - 1, j - 1);
			}
			for(int j = 1;j <= m;j++){
				add(a[i], ve[j], j);
			}
		}
		ans = get(n, m);
		
		printf("Case #%d: %d\n", ttt, ans);
	}
>>>>>>> Stashed changes
	return 0;
}
