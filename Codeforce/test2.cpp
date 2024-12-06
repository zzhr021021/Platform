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

#define csp(n) cout << n << " "
#define cend(n) cout << n << endl
#define cendl cout << endl
#define ctest cout << "test   "
#define pb push_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

const ll MOD = 1e9 + 7;
const ll MODD = 1e9 + 9;
const ll MOOD = 998244353;
ll p = MOOD;
const ll inf = 1e18;
const ll INF = 1e18;
const ll N = 1e6;
// ll dix[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
// ll diy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
using namespace std;
// mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());


ll tt, ttt;
ll n,k,m,t,x,y,z,h,r;

ll a[200050];
ll b[200050];
map<ll, ll> xij, yij;
map<ll, ll> xji, yji;
ll segu[500050], segd[500050];
ll li = 0;
ll ans = -1;
ll ansx, ansy;
void add(ll o, ll l, ll r, ll pos, ll val, ll seg[]){
	if(r < pos || l > pos)return;
	if(l == r){
		seg[o] += val;
		return;
	}
	ll mid = (l + r) >> 1;
	add(o << 1, l, mid, pos, val, seg);
	add(o << 1 | 1, mid + 1, r, pos, val, seg);
	seg[o] = seg[o << 1] + seg[o << 1 | 1];
}
ll query(ll o, ll l, ll r, ll L, ll R, ll seg[]){
	if(l > R || r < L)return 0;
	if(l >= L && r <= R)return seg[o];
	ll ret = 0;
	ll mid = (l + r) >> 1;
	ret += query(o << 1, l, mid, L, R, seg);
	ret += query(o << 1 | 1, mid + 1, r, L, R, seg);
	return ret;
}
ll cntall(ll seg[]){
	return query(1, 0, n, 0, n, seg);
}
ll whleft(ll cnt, ll seg[]){
	ll l = 0, r = n;
	while(l != r){
		ll mid = (l + r) >> 1;
		if(query(1, 0, n, 0, mid, seg) < cnt)l = mid + 1;
		else r = mid;
	}
	return l;
}
ll whright(ll cnt, ll seg[]){
	ll l = 0, r = n;
	while(l != r){
		ll mid = (l + r + 1) >> 1;
		if(query(1, 0, n, mid, n, seg) < cnt)r = mid - 1;
		else l = mid;
	}
	return l;
}
ll check(ll cnt){
	if(query(1, 0, n, 0, n, segu) < cnt * 2)return false;
	if(query(1, 0, n, 0, n, segd) < cnt * 2)return false;
	ll x1 = whleft(cnt, segd);
	ll x2 = whright(cnt, segd);
	if(x1 >= x2)return false;
	ll x3 = whleft(cnt, segu);
	if(x2 <= x3)return false;
	ll x4 = whright(cnt, segu);
	if(x3 >= x4)return false;
	if(x4 <= x1)return false;
	if(cnt > ans){
		ans = cnt;
		ansy = yji[li];
		ansx = xji[min(x2, x4)];
	}
	return true;
}

struct node{
	ll x, y;
};
bool cmp(const node & u, const node & v){
	return u.y < v.y;
}
vector<node> vo;

void sol(){
	cin>>n;
	rep(i,5 * n){
		segu[i] = segd[i] = 0;
	}
	set<ll> xs, ys;
	xij.clear();yij.clear();
	xji.clear();yji.clear();
	
	rep(i,n){
		cin>>a[i]>>b[i];
		xs.insert(a[i]);
		ys.insert(b[i]);
	}
	ll cdx = 0, cdy = 0;
	for(auto o : xs){
		xij[o] = cdx;
		xji[cdx] = o;
		cdx++;
	}
	for(auto o : ys){
		yij[o] = cdy;
		yji[cdy] = o;
		cdy++;
	}
	vo.clear();
	rep(i,n){
		a[i] = xij[a[i]];
		b[i] = yij[b[i]];
		vo.push_back({a[i], b[i]});
	}
	sort(all(vo), cmp);

	ans = -1;
	for(auto o : vo){
		add(1, 0, n, o.x, 1, segu);
	}
	ll po = 0;
	for(li = 0;li <= n + 1;li++){
		ll tadd = 0;
		while(po < n && vo[po].y < li){
			add(1, 0, n, vo[po].x, 1, segd);
			add(1, 0, n, vo[po].x, -1, segu);
			po++;
			tadd++;
		}
		if(tadd == 0)continue;
		if(!check(ans + 1))continue;
		if(query(1, 0, n, 0, n, segu) <= ans * 2)break;

		ll l = ans, r = 3e4;
		
		while(l != r){
			ll mid = (l + r + 1) >> 1;
			if(!check(mid))r = mid - 1;
			else l = mid;
		}
		check(l);
	}

	cend(ans);
	csp(ansx);csp(ansy);cendl;

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
