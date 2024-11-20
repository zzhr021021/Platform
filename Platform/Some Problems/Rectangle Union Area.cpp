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
ll n,k,m,t,x,y,z,w,h,q;

struct line{
	ll l, r, y, sn;
}lines[200005];
bool cmp(const line & u, const line & v){
	return u.y > v.y;
}
set<ll> xs;
ll cntx;
map<ll, ll> inj;
vll xar;

ll olen[800050];
ll seg[800050];
ll lazy[800050];

void build(ll o, ll l, ll r){
	if(l == r)olen[o] = xar[l];
	else{
		ll mid = (l + r) / 2;
		build(o << 1, l, mid);
		build(o << 1 | 1, mid + 1, r);
		olen[o] = olen[o << 1] + olen[o << 1 | 1];
	}
}
ll get(ll o, ll l, ll r){
	return seg[o] + lazy[o] * (r - l + 1);
}
void maintain(ll o, ll l, ll r){
	if(lazy[o]){
		seg[o] = olen[o];
	}
	else if(l == r){
		seg[o] = 0;
	}
	else{
		seg[o] = seg[o << 1] + seg[o << 1 | 1];
	}
	
}
void add(ll o, ll l, ll r, ll L, ll R, ll val){
	if(R < l || L > r)return;
	else if(l >= L && r <= R){
		lazy[o] += val;
		maintain(o, l, r);
	}
	else{
		ll mid = (l + r) / 2;
		add(o << 1, l, mid, L, R, val);
		add(o << 1 | 1, mid + 1, r, L, R, val);
		maintain(o, l, r);
	}
}

void sol(){
	// input and preprocess
	cin>>n;
	ll nl = n * 2;
	rep(i,n){
		cin>>x>>y>>z>>w;
		xs.insert(x);
		xs.insert(z);
		lines[i * 2] = {x, z, w, 1};
		lines[i * 2 + 1] = {x, z, y, -1};
	}
	sort(lines, lines + 2 * n, cmp);
	ll last = 0;
	for(auto o : xs){
		if(cntx != 0)xar.push_back(o - last);
		inj[o] = cntx;
		cntx++;
		last = o;
	}
	ll nn = xar.size();
	build(1, 0, nn - 1);
	
	// get answer
	ll ans = 0;
	rep(iline, nl - 1){
		ll gap = lines[iline].y - lines[iline + 1].y; 
		ll L = inj[lines[iline].l];
		ll R = inj[lines[iline].r] - 1;
		add(1, 0, nn - 1, L, R, lines[iline].sn);
		ans += seg[1] * gap;
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
