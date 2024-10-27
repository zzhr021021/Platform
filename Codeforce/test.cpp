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
ll dix[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
ll diy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
using namespace std;
// mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

ll tt, ttt;
ll n,k,m,d,t,x,y,z,h, q;

void printvec(vll & v){
	for(ll &x : v){
		cout << x << " ";
	}
	cendl;
}

#define node array<ll, 10>
ll primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
ll divmin[1024];
ull base = 13331;
set<ull> rec;
ull gethash(node & o){
	ll ret = 0;
	for(auto x : o){
		ret *= base;
		ret += x;
	}
	return ret;
}
bool outbound(node & o){
	ll cnt = 0;
	for(auto x : o){
		cnt += x;
	}
	if(cnt >= 31)return true;
	return false;
}
ll cntdiv(node & o){
	ll cnt = 1;
	for(auto x : o){
		cnt *= (x + 1);
	}
	return cnt;
}
void printnode(node & o){
	rep(i,10){
		csp(o[i]);
	}
	cendl;
}
void dfs(node o, ll x){
	// ctest;printnode(o);cend(x);
	if(outbound(o))return;
	if(x > 2e9)return;
	ull thehash = gethash(o);
	if(rec.count(thehash))return;
	rec.insert(thehash);
	ll divcnt = cntdiv(o);
	divmin[divcnt] = min(divmin[divcnt], x);
	rep(i,10){
		node u = o;
		if(i == 0){
			u[0]++;
			dfs(u, x * primes[0]);
		}
		else{
			if(u[i] < u[i - 1]){
				u[i]++;
				dfs(u, x * primes[i]);
			}
		}
	}
}

void sol(){
	rep(i,1024){
		divmin[i] = inf;
	}
	cin>>n;
	node sto;
	rep(i,10){
		sto[i] = 0;
	}
	dfs(sto, 1);
	ll ans = 0;
	rep(i,1024){
		if(divmin[i] != inf && divmin[i] <= n){
			ans = divmin[i];
		}
	}
	cend(ans);

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