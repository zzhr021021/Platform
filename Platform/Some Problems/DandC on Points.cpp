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

struct node{
	ll wh, le;
};
bool cmp(const node & u, const node & v){
	return u.le < v.le;
}
queue<ll> q;
vpl g[50000];
unordered_set<ll> vis;
ll sz[50000];
ll cntwh[50050];
vector<node> ost;
ll gsz = 0;
ll gmx = 1e9;
ll grt = 0;
ll ans = 0;

ll get_hash(ll x, ll y){
	return x * 1e9 + y;
}
ll set_sz(ll o, ll fa){
	ll ret = 1;
	for(auto ad : g[o]){
		if(ad.first != fa && vis.count(get_hash(o, ad.first)) == 0){
			ret += set_sz(ad.first, o);
		}
	}
	if(fa == -1){
		gsz = ret;
	}
	return ret;
}
ll get_rt(ll o, ll fa){
	ll ret = 1;
	ll mx = 0;
	for(auto ad : g[o]){
		if(ad.first != fa && vis.count(get_hash(o, ad.first)) == 0){
			ll tp = get_rt(ad.first, o);
			ret += tp;
			mx = max(mx, tp);
		}
	}
	if(fa != -1){
		mx = max(mx, gsz - ret);
	}
	if(mx < gmx){
		gmx = mx;
		grt = o;
	}
	sz[o] = ret;
	return ret;
}
void set_le(ll o, ll fa, ll wh, ll dist){
	for(auto ad : g[o]){
		if(ad.first != fa && vis.count(get_hash(o, ad.first)) == 0){
			if(fa == -1){
				set_le(ad.first, o, ad.first, dist + ad.second);
			}
			else{
				set_le(ad.first, o, wh, dist + ad.second);
			}
		}
	}
	if(fa != -1){
		ost.push_back({wh, dist});
		if(dist <= k)ans++;
	}
}

// Luogu P4178 tree
// given an undirected tree with positive-valued-edges, and an integer k
// answer how many path whose length is not greater than k
void sol(){
	// input
	cin>>n;
	rep(i,n - 1){
		cin>>x>>y>>z;
		g[x].push_back({y,z});
		g[y].push_back({x,z});
	}
	cin>>k;

	// queue
	q.push(1);	
	while(q.size()){
		ll x = q.front();
		q.pop();
		set_sz(x, -1);
		gmx = 1e9;
		get_rt(x, -1);
		ost.clear();
		set_le(grt, -1, -1, 0);
		sort(all(ost), cmp);
		memset(cntwh, 0, sizeof(cntwh));
		for(auto o : ost){
			cntwh[o.wh]++;
		}
		ll r = ost.size() - 1;
		ll tans = 0;
		for(int l = 0;l < ost.size();l++){
			node o = ost[l];
			cntwh[o.wh]--;
			
			while(r >= 0 && o.le + ost[r].le > k){
				cntwh[ost[r].wh]--;
				r--;
			}
			if(l >= r)break;
			tans += r - l - cntwh[o.wh];
		}
		ans += tans;
		for(auto ad : g[grt]){
			if(vis.count(get_hash(grt, ad.first)) == 0){
				q.push(ad.first);
				vis.insert(get_hash(grt, ad.first));
				vis.insert(get_hash(ad.first, grt));
			}
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
