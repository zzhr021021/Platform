#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)
#define rep1nr(i, n) for (int i = (n); i >= 1; --i)
#define rep01n(i, n) for (int i = 0; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)

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
const ll MOOD = 666623333;
ll p = MOD;
const ll inf = 1e18;
const ll INF = 1e18; 
// ll dix[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
// ll diy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
using namespace std;
// mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

ll tt, ttt;
ll n,k,m,t,x,y,z,h,q;

#define NODE array<array<ll, 4>, 4>
ll convint(NODE & o){
    ll ret = 0;
    rep(i,4){
        rep(j,4){
            ret *= 2;
            ret += o[i][j];
        }
    }
    return ret;
}
NODE convnode(ll x){
    NODE ret;
    repr(i,4){
        repr(j,4){
            ret[i][j] = x % 2;
            x /= 2;
        }
    }
    return ret;
}
void clearnode(NODE & o){
    rep(i,4){
        rep(j,4)o[i][j] = 1;
    }
}
bool isgood(NODE & o){
    rep(i,4){
        if(o[i][0] == 1)return false;
    }
    return true;
}
void printnode(NODE & o){
    rep(i,4){
        rep(j,4){
            csp(o[i][j]);
        }
        cendl;
    }
}

ll a[10];
ll mat[4][1100];
ll dp[1100][70000];
vector<NODE> ops;
vector<ll> css;

void sol(){
    // prep
    cin>>n;
    rep1n(i,4)cin>>a[i];

    map<ll, ll> inj;
    rep(i,5){
        rep(j,4){
            rep(ii,3){
                rep(jj,2){
                    NODE o;
                    ll cost = 0;
                    clearnode(o);
                    rep(ki, i){
                        rep(kj, i){
                            o[kj + 0][3 - ki] = 0;
                        }
                    }
                    cost += a[i];
                    rep(ki, j){
                        rep(kj, j){
                            o[kj + 1][3 - ki] = 0;
                        }
                    }
                    cost += a[j];
                    rep(ki, ii){
                        rep(kj, ii){
                            o[kj + 2][3 - ki] = 0;
                        }
                    }
                    cost += a[ii];
                    rep(ki, jj){
                        rep(kj, jj){
                            o[kj + 3][3 - ki] = 0;
                        }
                    }
                    cost += a[jj];
                    ll hs = convint(o);
                    if(inj[hs] == 0){
                        inj[hs] = cost;
                    }
                    else if(cost < inj[hs]){
                        inj[hs] = cost;
                    }
                }
            }
        }
    }
    for(auto o : inj){
        NODE u = convnode(o.first);
        ops.push_back(u);
        css.push_back(o.second);
    }

    // input
    
    rep(i,4){
        string s;cin>>s;
        rep(j,n){
            if(s[j] == '*'){
                mat[i][j + 4] = 1;
            }
        }
    }
    n += 4;

    // process
    memset(dp, 0x3f, sizeof(dp));
    dp[3][0] = 0;
    



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