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

ll base = 5;
ll fa[500000];

vector<pll> op;

ll getfa(ll o){
	if(fa[o] == o)return o;
	// ctest;csp(o);csp(fa[o]);cendl;
	op.push_back({o, fa[o]});
	fa[o] = getfa(fa[o]);
	return fa[o];
}

void recover(){
	while(op.size()){
		auto o = op.back();
		fa[o.first] = o.second;
		op.pop_back();
	}
}

ll merge(ll u, ll v){
	u = getfa(u);
	v = getfa(v);
	op.push_back({v, fa[v]});
	fa[v] = u;
	return u;
}

void sol(){
	// init;
	rep(i,60000){
		rep(j,4){
			fa[i * base + j] = i * base + j;
		}
	}

	// process
	cin>>n>>k;
	ll fal = 0;
	rep(i,k){
		
		// ctest;
		// csp(i + 1);csp(fal);cendl;
		op.clear();
		cin>>z>>x>>y;
		if(x > n || y > n)fal++;
		else{
			if(z == 1){
				merge(x * base + 0, y * base + 0);
				merge(x * base + 1, y * base + 1);
				merge(x * base + 2, y * base + 2);
				if(getfa(x * base + 0) == getfa(x * base + 1)){
					fal++;
					recover();continue;
				}
				if(getfa(x * base + 2) == getfa(x * base + 1)){
					fal++;
					recover();continue;
				}
				if(getfa(x * base + 0) == getfa(x * base + 2)){
					fal++;
					recover();continue;
				}
				if(getfa(y * base + 0) == getfa(y * base + 1)){
					fal++;
					recover();continue;
				}
				if(getfa(y * base + 2) == getfa(y * base + 1)){
					fal++;
					recover();continue;
				}
				if(getfa(y * base + 0) == getfa(y * base + 2)){
					fal++;
					recover();continue;
				}
			}
			else{
				merge(x * base + 0, y * base + 1);
				merge(x * base + 1, y * base + 2);
				merge(x * base + 2, y * base + 0);
				if(getfa(x * base + 0) == getfa(x * base + 1)){
					fal++;
					recover();continue;
				}
				if(getfa(x * base + 2) == getfa(x * base + 1)){
					fal++;
					recover();continue;
				}
				if(getfa(x * base + 0) == getfa(x * base + 2)){
					fal++;
					recover();continue;
				}
				if(getfa(y * base + 0) == getfa(y * base + 1)){
					fal++;
					recover();continue;
				}
				if(getfa(y * base + 2) == getfa(y * base + 1)){
					fal++;
					recover();continue;
				}
				if(getfa(y * base + 0) == getfa(y * base + 2)){
					fal++;
					recover();continue;
				}
			}
		}
	}
	cend(fal);
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
