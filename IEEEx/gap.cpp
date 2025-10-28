#include<bits/stdc++.h>
#define debug(x) cout << #x << " = " << x << endl
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (ll i = 1; i <= (n); ++i)
#define rep1nr(i, n) for (int i = (n); i >= 1; --i)
#define rep01n(i, n) for (int i = 0; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define replr(i, l, r) for (int i = l;i <= r;i++)
#define repij(i, j, n, m) for (int i = 0; i < (n); ++i) for (int j = 0; j < (m); ++j)

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

const ll MOD = 1e9 + 7;
const ll inf = 1e18;
const ll INF = 1e18;
const ll N = 200500;
// ll dix[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
// ll diy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
using namespace std;
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
void ckmax(ll & x, ll y){
	if(y > x)x = y;
}
void ckmin(ll & x, ll y){
	if(y < x)x = y;
}
void printvec(vll & v){
	for(auto o : v){
		csp(o);
	}
	cendl;
}
void printvec(vpl & v){
	for(auto o : v){
		csp(o.first);csp(o.second);csp("   ");
	}
	cendl;
}
ll tt, ttt;
ll n,k,m,t,x,y,z,h,q,d,s;

ll a[200500];
ll b[200500];

ll ladder(ll x){
	return (1 + x) * x / 2;
}
ll sq(ll x){
	return x * x;
}
ll bigger(ll x, ll y, ll z, ll w){
    if(x < 0){
        x = -x;
        y = -y;
    }
    if(z < 0){
        z = -z;
        w = -w;
    }
    return x * w <= y * z;
}

void sol(){
	string s1, s2;
	cin>>n>>s1>>m>>s2;
	n++;m++;
	s1 += 'T';
	s2 += 'T';
	
	cin>>x>>y>>z;
	ll ans[n + 5][m + 5];
    vpl conh[n + 5], conv[m + 5];

	rep(i,n + 5){
		rep(j,m + 5){
			ans[i][j] = -inf;
		}
	}
	rep(i,n){
		rep(j,m){
			if(i == 0 && j == 0){
				if(s1[i] == s2[j]){
					ans[i][j] = x;
				}
				else{
					ans[i][j] = y;
				}
			}
			else if(i == 0){
				ans[i][j] = (j * j) * z;
				if(s1[i] == s2[j]){
					ans[i][j] += x;
				}
				else{
					ans[i][j] += y;
				}
			}
			else if(j == 0){
				ans[i][j] = (i * i) * z;
				if(s1[i] == s2[j]){
					ans[i][j] += x;
				}
				else{
					ans[i][j] += y;
				}
			}
			else{
				ll base = x;
				// if(s1[i] != s2[j])base = y;
				// for(int ii = 0;ii <= i - 1;ii++){
				// 	ans[i][j] = max(ans[i][j], ans[ii][j - 1] + sq(i - ii - 1) * z + base);
				// }
				// for(int jj = 0;jj <= j - 1;jj++){
				// 	ans[i][j] = max(ans[i][j], ans[i - 1][jj] + sq(j - jj - 1) * z + base);
				// }
                // ask convex
                ll slope, dx, dy;
                // horizontal
                slope = 2 * z * j;
                if(conh[i - 1].size() > 1){
                    dx = conh[i - 1][0].first - conh[i - 1][1].first;
                    dy = conh[i - 1][0].second - conh[i - 1][1].second;
                }
                if(conh[i - 1].size() == 1 || bigger(1, slope, dx, dy)){
                    // get 0
                    ans[i][j] = max(ans[i][j], ans[i - 1][0] + sq(j - 0 - 1) * z + base);
                }
                else{
                    ll l = 0, r = conh[i - 1].size() - 1;
                    while(l != r){
                        ll mid = (l + r) / 2;
                        dx = conh[i - 1][mid].first - conh[i - 1][mid + 1].first;
                        dy = conh[i - 1][mid].second - conh[i - 1][mid + 1].second;
                        if(bigger(1, slope, dx, dy)){
                            l = mid + 1;
                        }
                        else{
                            r = mid;
                        }
                    }
                    ans[i][j] = max(ans[i][j], ans[i - 1][l] + sq(j - l - 1) * z + base);
                }

                // vertical
                slope = 2 * z * i;
                if(conv[j - 1].size() > 1){
                    dx = conv[j - 1][0].first - conv[j - 1][1].first;
                    dy = conv[j - 1][0].second - conv[j - 1][1].second;
                }
                if(conv[j - 1].size() == 1 || bigger(1, slope, dx, dy)){
                    // get 0
                    ans[i][j] = max(ans[i][j], ans[0][j - 1] + sq(i - 0 - 1) * z + base);
                }
                else{
                    ll l = 0, r = conv[j - 1].size() - 1;
                    while(l != r){
                        ll mid = (l + r) / 2;
                        dx = conv[j - 1][mid].first - conv[j - 1][mid + 1].first;
                        dy = conv[j - 1][mid].second - conv[j - 1][mid + 1].second;
                        if(bigger(1, slope, dx, dy)){
                            l = mid + 1;
                        }
                        else{
                            r = mid;
                        }
                    }
                    ans[i][j] = max(ans[i][j], ans[l][j - 1] + sq(i - l - 1) * z + base);
                }
			}
            // maintain convex
            // horizontal
            if(conh[i].size() <= 1){
                conh[i].push_back({j, ans[i][j]});
            }
            else{
                while(conh[i].size() >= 2){
                    ll tn = conh[i].size();
                    ll dx1 = conh[i][tn - 1].first - conh[i][tn - 2].first;
                    ll dy1 = conh[i][tn - 1].second - conh[i][tn - 2].second;
                    ll dx2 = conh[i][tn - 1].first - j;
                    ll dy2 = conh[i][tn - 1].second - ans[i][j];
                    if(bigger(dx2, dy2, dx1, dy1)){
                        ctest;csp("pop");
                        csp(conh[i][tn - 2].first);csp(conh[i][tn - 2].second);
                        csp(conh[i][tn - 1].first);csp(conh[i][tn - 1].second);
                        csp(j);csp(ans[i][j]);cendl;
                        csp(dx2);csp(dy2);csp(dx1);csp(dy1);
                        csp(bigger(dx2, dy2, dx1, dy1));
                        cendl;
                        conh[i].pop_back();
                    }n
                    else{
                        break;
                    }
                }
                conh[i].push_back({j, ans[i][j]});
            }

            // vertical
            if(conv[j].size() <= 1){
                conv[j].push_back({i, ans[i][j]});
            }
            else{
                while(conv[j].size() >= 2){
                    ll tn = conv[j].size();
                    ll dx1 = conv[j][tn - 1].first - conv[j][tn - 2].first;
                    ll dy1 = conv[j][tn - 1].second - conv[j][tn - 2].second;
                    ll dx2 = conv[j][tn - 1].first - i;
                    ll dy2 = conv[j][tn - 1].second - ans[i][j];
                    if(bigger(dx2, dy2, dx1, dy1)){
                        conv[j].pop_back();
                    }
                    else{
                        break;
                    }
                }
                conv[j].push_back({i, ans[i][j]});
            }
//			ctest;csp(i);csp(j);cend(ans[i][j]);
            ctest;csp(i);cend(j);
            printvec(conv[0]);
            printvec(conh[0]);
		}		
	}
    
	cend(ans[n - 1][m - 1] - x);
	
}

ll tnt(){
	while(1){
	}
	return 0;
}


int main(){
	// ios_base::sync_with_stdio(false);
	// cin.tie(nullptr);
	// cout.tie(nullptr);
	
	tt = 1;
//	cin>>tt;
	for(ttt = 1;ttt <= tt;ttt++){
		sol();
	}
	system("pause");
	return 0;
}