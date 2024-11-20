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
 mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

ll tt, ttt;
ll n,k,m,t,x,y,z,w,h,q;

struct line{
	ll l, r, y, v;
};
vector<line> lines;
bool cmp(const line & u, const line & v){
	return u.y > v.y;
}

ll a[20005];
ll b[20005];
ll seg[80050];
ll segmx[80050];
ll lazy[80050];

ll get(ll o, ll l, ll r){
	return seg[o] + lazy[o] * (r - l + 1);
}
void maintain(ll o, ll l, ll r){
	seg[o] = seg[o << 1] + seg[o << 1 | 1];
	segmx[o] = max(segmx[o << 1], segmx[o << 1 | 1]);
	lazy[o] = 0;
}
void propagate(ll o, ll l, ll r){
	if(l != r){
		ll mid = (l + r) / 2;
		lazy[o << 1] += lazy[o];
		seg[o << 1] += lazy[o] * (mid - l + 1);
		segmx[o << 1] += lazy[o];
		
		lazy[o << 1 | 1] += lazy[o];
		seg[o << 1 | 1] += lazy[o] * (r - mid);
		segmx[o << 1 | 1] += lazy[o];
		lazy[o] = 0;
	}
}
void add(ll o, ll l, ll r, ll L, ll R, ll val){
	if(R < l || L > r)return;
	if(l >= L && r <= R){
		seg[o] += val * (r - l + 1);
		segmx[o] += val;
		lazy[o] += val;
	}
	else{
		ll mid = (l + r) / 2;
		propagate(o, l, r);
		add(o << 1, l, mid, L, R, val);
		add(o << 1 | 1, mid + 1, r, L, R, val);
		maintain(o, l, r);
	}
}
ll query(ll o, ll l, ll r, ll L, ll R){
	if(r < L || l > R)return 0;
	if(l >= L && r <= R){
		return seg[o];
	}
	else{
		propagate(o, l, r);
		ll mid = (l + r) / 2;
		ll ret = query(o << 1, l, mid, L, R);
		ret += query(o << 1 | 1, mid + 1, r, L, R);
		return ret;
	}
}
ll querymx(ll o, ll l, ll r, ll L, ll R){
	if(r < L || l > R)return -inf;
	if(l >= L && r <= R){
		return segmx[o];
	}
	else{
		propagate(o, l, r);
		ll mid = (l + r) / 2;
		ll ret = max(querymx(o << 1, l, mid, L, R), querymx(o << 1 | 1, mid + 1, r, L, R));
		return ret;
	}
}

// Luogu P1502 
// given some valued fixed points and a rectangle sizing (w, h)
// place anywhere the rectangle, answer the maximum sum of value of the points that in the rectangle
void sol(){
	memset(seg, 0, sizeof(seg));
	memset(segmx, 0, sizeof(segmx));
	memset(lazy, 0, sizeof(lazy));
	lines.clear();
	// input 
	cin>>n>>w>>h;
	set<ll> xs;
	map<ll, ll> inj;
	rep(iline, n){
		cin>>x>>y>>z;
		lines.push_back({x, x + w, y + h, z});
		lines.push_back({x, x + w, y, -z});
		xs.insert(x);
		xs.insert(x + w);
	}
	ll cntx = 0;
	for(auto o : xs){
		inj[o] = cntx;
		cntx++;
	}
	sort(all(lines), cmp);
	ll nn = cntx - 1; 
	
	// get answer;
	ll ans = 0;
	for(line o : lines){
//		ctest;csp(o.l);csp(o.r);csp(o.y);csp(o.v);cendl;
		
		add(1, 0, nn - 1, inj[o.l], inj[o.r] - 1, o.v);
		
//		ctest;csp(querymx(1, 0, nn - 1, 0, nn - 1));cendl;
		
		ans = max(ans, querymx(1, 0, nn - 1, 0, nn - 1));
	}
	cend(ans);
	


}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	tt = 1;
	 cin>>tt;
	for(ttt = 1;ttt <= tt;ttt++){
		sol();
	}
	system("pause");
	return 0;
}
