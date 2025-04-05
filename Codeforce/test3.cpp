#include<bits/stdc++.h>
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

#define csp(n) cout << n << " "
#define cend(n) cout << n << endl
#define cendl cout << endl
#define ctest cout << "test   "
 
using namespace std;
void ckmax(ll & x, ll y){
	if(y > x)x = y;
}
void ckmin(ll & x, ll y){
	if(y < x)x = y;
}

ll tt, ttt;
ll n,k,m,t,x,y,z;

vll g[200500];
ll fa[200500];

ll stringtonum(string & s, ll l, ll r){
	ll ret = 0;
	ctest;cend(s);
	for(int i = r;i >= l;i++){
		ret *= 10;
		ret += s[i] - 'a';
	}
	return ret;
}
pll getdata(string & s){
	ll sn = s.size();
	ll pp = 0;
	while(s[pp] != ':')pp++;
	pll ret;
	ret.first = stringtonum(s, 0, pp - 1);
	ret.second = stringtonum(s, pp + 2, sn - 1);
	return ret;
}
void sol(){
	while(cin>>n){
		rep(i,n + 5){
			g[i].clear();
		}
		rep(i,n){
			string s;cin>>s;
			pll dt = getdata(s);
			rep(j,dt.second){
				cin>>x;
				g[dt.first].push_back(x);
				fa[x] = dt.first;
			}
		}

	}	
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