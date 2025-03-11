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
ll p = MOD;
const ll inf = 1e18;
const ll INF = 1e18;
const ll N = 200500;
// ll dix[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
// ll diy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
using namespace std;
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

void printvec(vll & v){
	for(auto o : v){
		csp(o);
	}
	cendl;
}

ll tt, ttt;
ll n,k,m,t,x,y,z,h,s;

ll D[200500];
ll DD[200500];
ll H[300500];
ll T[300500];
ll CAT[200500];
ll S[200500];
ll dp[105][100500];

pll qu[200500];
ll l, r;
double getk(ll x1, ll y1, ll x2, ll y2){
    return double(y2 - y1) / (x2 - x1);
}

void sol(){
    cin>>n>>m>>p;
    for(int i = 2;i <= n;i++){
        cin>>D[i];
        DD[i] = DD[i - 1] + D[i];
    }
    rep1n(i,m){
        cin>>H[i]>>T[i];
    }
    rep1n(i,m){
        CAT[i] = T[i] - DD[H[i]];
    }
    sort(CAT + 1, CAT + 1 + m);
    rep1n(i,m){
        S[i] = S[i - 1] + CAT[i];
    }
    // init dp
    rep1n(i,m){
        dp[0][i] = inf;
    }

    rep1n(i,p){
        l = r = 1;
        qu[1] = {0, 0};
        rep1n(j,m){
            ll yuzu = CAT[j];
            // maintain
            while(r - l + 1 >= 2 && getk(qu[l].first, qu[l].second, qu[l + 1].first, qu[l + 1].second) <= yuzu){
                l++;
            }
            // update
            // ctest;csp("update");csp(l);csp(qu[l].first);csp(qu[l].second);cendl;
            // ctest;csp("update");csp(qu[l].second);csp(yuzu * qu[l].first);csp(yuzu * j);csp(S[j]);cendl;
            dp[i][j] = qu[l].second - yuzu * qu[l].first + yuzu * j - S[j];
            // maintain
            x = j;
            y = dp[i - 1][j] + S[j];
            while(r - l + 1 >= 2 && getk(qu[r].first, qu[r].second, qu[r - 1].first, qu[r - 1].second) >= getk(qu[r].first, qu[r].second, x, y)){
                r--;
            }
            qu[++r] = {x, y};

            // ctest;csp(i);csp(j);cend(dp[i][j]);
        }
    }
    cend(dp[p][m]);
}

int main(){
	// ios_base::sync_with_stdio(false);
	// cin.tie(nullptr);
	// cout.tie(nullptr);
	
	tt = 1;
	// cin>>tt;
	for(ttt = 1;ttt <= tt;ttt++){
		sol();
	}
	system("pause");
	return 0;
}