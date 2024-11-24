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

void printvec(vll & v){
	for(auto o : v){
		csp(o);
	}
	cendl;
}

ll tt, ttt;
ll n,k,m,t,x,y,z,h,r;

ll ghs(ll x, ll y){
	return x * 2 + y;
}

ll a[100050];
ll b[100050];
ll c[100050];

ll fa[200050];
ll getfa(ll o){
	if(fa[o] == o)return o;
	else return fa[o] = getfa(fa[o]);
}
ll merge(ll u, ll v){
	u = getfa(u);
	v = getfa(v);
	fa[v] = u;
	return u;
}

bool check(ll x){
	rep(i,m){
		if(c[i] > x){
			if(getfa(ghs(a[i], 0)) == getfa(ghs(b[i], 0)))return false;
			if(getfa(ghs(a[i], 1)) == getfa(ghs(b[i], 1)))return false;
			merge(ghs(a[i], 0), ghs(b[i], 1));
			merge(ghs(a[i], 1), ghs(b[i], 0));
		}
	}
	return true;
}

void sol(){
	cin>>n>>m;
	rep(i,m){
		cin>>a[i]>>b[i]>>c[i];
	}

	ll l = 0, r = 1e9 + 7;
	while(l != r){
		rep1n(i,n){
			rep(j,2){
				fa[ghs(i, j)] = ghs(i, j);
			}
		}
		ll mid = (l + r) / 2;
		if(check(mid))r = mid;
		else l = mid + 1;
	}
	cend(l);
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
