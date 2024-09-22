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

const ll MOD = 1e9+7;
const ll MODD = 1e9+9;
const ll MOOD = 998244353;
ll p = MOD;
const ll inf = 1e18;
const ll INF = 1e18; 
const int N = 200005;
using namespace std;
 
ll tt;
ll ttt;
ll n,k,m,d,q,t,x,y,z,h;
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

void printvec(vll & v){
	for(ll &x : v){
		cout << x << " ";
	}
	cendl;
}

ll mygcd(ll x, ll y){
	if(x == 0 && y == 0)return inf;
	return __gcd(x, y);
}

void sol(){
	ll n;
	cin>>n;
	vll a(n);
	ll g = 0;
	rep(i,n){
		cin>>a[i];
		g = __gcd(g, a[i]);
	}
	rep(i,n){
		a[i] /= g;
	}
	
	a.pb(0);
	
	ll ans = 0;
	ll cur = 0;
	vb vis(n + 1);
	rep(i,n){
		if(cur == 1){
			ans += n - i;
			break;
		}
		ll rec = n;
		rep(j,n){
			if(vis[j] == false){
				if(mygcd(cur, a[j]) < mygcd(cur, a[rec])){
					rec = j;
				}
			}
		}
		vis[rec] = true;
		cur = __gcd(cur, a[rec]);
		ans += cur;
	}
	cend(ans * g);
}


int main(){
	// ios_base::sync_with_stdio(false);
	// cin.tie(nullptr);
	// cout.tie(nullptr);
		
	tt = 1;
	cin>>tt;
	for(ttt = 1;ttt <= tt;ttt++){
		sol();
	}
//    system("pause");
	return 0;
}
