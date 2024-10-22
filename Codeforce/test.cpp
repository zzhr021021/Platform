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


const ll MOD = 1e9;
const ll MODD = 1e9+9;
const ll MOOD = 998244353;
ll p = MOD;
const ll inf = 1e18;
const ll INF = 1e18; 
const int N = 200005;
// ll dix[4] = {0, -1, 0, 1};
// ll diy[4] = {1, 0, -1, 0};
using namespace std;
// mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

ll tt, ttt;
ll n,k,m,d,q,t,x,y,z,h;

void printvec(vll & v){
	for(ll &x : v){
		cout << x << " ";
	}
	cendl;
}

ll sym[30];
bool occ[30];
string s[3];
void printstate(){
	rep(i,3){
		rep(j,n){
			if(sym[s[i][j] - 'A'] == -1){
				csp(-1);
			}
			else{
				csp(sym[s[i][j] - 'A']);
			}
		}
		cendl;
	}
	cendl;
}
bool dfs(ll x, ll y, ll asd){
	if(x == -1){
		ll tp = 0;
		while(sym[tp] != -1){
			csp(sym[tp]);
			tp++;
		}
		return true;
	}
	for(int i = x - 1;i >= 0;i--){
		if(sym[s[0][i]] != -1 && sym[s[1][i]] != -1 && sym[s[2][i]] != -1){
			if(((sym[s[0][i]] + sym[s[1][i]]) % n != sym[s[2][i]]) && ((sym[s[0][i]] + sym[s[1][i]] + 1) % n != sym[s[2][i]])){
				return false;
			}
		}
	}
	if(x != 0){
		if(y <= 1){
			if(sym[s[y][x] - 'A'] == -1){
				for(int i = n - 1;i >= 0;i--){
					if(occ[i] == false){
						sym[s[y][x] - 'A'] = i;
						occ[i] = true;
						bool ret = dfs(x, y + 1, asd);
						if(ret)return true;
						occ[i] = false;
						sym[s[y][x] - 'A'] = -1;
					}
				}
				return false;
			}
			else{
				bool ret = dfs(x, y + 1, asd);
				if(ret)return true;
			}
		}
		else{
			if(sym[s[y][x] - 'A'] == -1){
				for(int i = n - 1;i >= 0;i--){
					if(occ[i] == false){
						if((sym[s[0][x] - 'A'] + sym[s[1][x] - 'A'] + asd) % n != i){
							continue;
						}
						sym[s[y][x] - 'A'] = i;
						occ[i] = true;
						bool ret = dfs(x - 1, 0, (sym[s[0][x] - 'A'] + sym[s[1][x] - 'A'] + asd) / n);
						if(ret)return true;
						occ[i] = false;
						sym[s[y][x] - 'A'] = -1;
					}
				}
				return false;
			}
			else{
				if((sym[s[0][x] - 'A'] + sym[s[1][x] - 'A'] + asd) % n != sym[s[2][x] - 'A']){
					return false;
				}
				bool ret = dfs(x - 1, 0, (sym[s[0][x] - 'A'] + sym[s[1][x] - 'A'] + asd) / n);
				if(ret)return true;
			}
		}
	}
	else{
		if(y <= 1){
			if(sym[s[y][x] - 'A'] == -1){
				for(int i = n - 1;i >= 0;i--){
					if(occ[i] == false){
						sym[s[y][x] - 'A'] = i;
						occ[i] = true;
						bool ret = dfs(x, y + 1, asd);
						if(ret)return true;
						occ[i] = false;
						sym[s[y][x] - 'A'] = -1;
					}
				}
				return false;
			}
			else{
				bool ret = dfs(x, y + 1, asd);
				if(ret)return true;
			}
		}
		else{
			if(sym[s[y][x] - 'A'] == -1){
				for(int i = n - 1;i >= 0;i--){
					if(occ[i] == false){
						if((sym[s[0][x] - 'A'] + sym[s[1][x] - 'A'] + asd) % n != i){
							continue;
						}
						if((sym[s[0][x] - 'A'] + sym[s[1][x] - 'A'] + asd) >= n){
							continue;
						}
						sym[s[y][x] - 'A'] = i;
						occ[i] = true;
						bool ret = dfs(x - 1, 0, (sym[s[0][x] - 'A'] + sym[s[1][x] - 'A'] + asd) / n);
						if(ret)return true;
						occ[i] = false;
						sym[s[y][x] - 'A'] = -1;
					}
				}
				return false;
			}
			else{
				if((sym[s[0][x] - 'A'] + sym[s[1][x] - 'A'] + asd) % n != sym[s[2][x] - 'A']){
					return false;
				}
				if((sym[s[0][x] - 'A'] + sym[s[1][x] - 'A'] + asd) >= n){
					return false;
				}
				bool ret = dfs(x - 1, 0, (sym[s[0][x] - 'A'] + sym[s[1][x] - 'A'] + asd) / n);
				if(ret)return true;
			}
		}
	}
	return false;
}

void sol(){
	cin>>n;
	
	rep(i, 3)cin>>s[i];
	vll v1(n), v2(n), v3(n);
	rep(i,30)sym[i] = -1;
	dfs(n - 1, 0, 0);

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