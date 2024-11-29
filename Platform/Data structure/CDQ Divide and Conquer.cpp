#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)

#define ll long long
#define ull unsigned long long
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define vb vector<bool>

#define csp(n) cout << n << " "
#define cend(n) cout << n << endl
#define cendl cout << endl
#define ctest cout << "test   "
#define all(a) a.begin(), a.end()
const ll inf = 1e18;
const ll N = 1e6;
using namespace std;

ll tt, ttt;
ll n,m,x,y;

struct NODE{
	ll op,x,y,ind;
	inline bool operator<(const NODE & o){
		return x < o.x;
	}
}ve[600006], ev[600006], tp[600006];
void rotate(NODE & o){
	ll x = N - o.y;
	ll y = o.x;
	o.x = x;o.y = y;
}
ll qcnt, pcnt;
ll ans[300005];

struct segop{
	ll loc, val;
};

// BIT
stack<segop> q;
vll fenw(1000050, -inf);
ll pa(ll x){
	ll tp = x & (-x);
	return x - tp;
}
void modify(int pos, long long val){
    while (pos < fenw.size()){
        q.push({pos, fenw[pos]});
        fenw[pos] = max(fenw[pos], val);
        pos |= (pos + 1);
    }
}
 
ll query(int pos){
    ll res = -inf;
    while (pos >= 0){
        res = max(res, fenw[pos]);
        pos &= (pos + 1);
        pos--;
    }
    return res;
}
void deleteops(){
	while(q.size()){
		auto o = q.top();
		q.pop();
        fenw[o.loc] = o.val;
	}
}

void get_st(vector<NODE> & o){
	for(int i = 0;i < o.size();i++){
		if(o[i].op == 1){
            modify(o[i].y, o[i].x + o[i].y);
		}
		else if(o[i].op == 2){
			ll tp = query(o[i].y);
			ans[o[i].ind] = min(ans[o[i].ind], o[i].x + o[i].y - tp);
		}
	}
}
void CDQ(ll l, ll r){
	vector<NODE> ret;
	if(l == r){
		return;
	}
	ll mid = (l + r) / 2;
	CDQ(l, mid);
	CDQ(mid + 1, r);
	// get
	vector<NODE> uu;
	vector<NODE> vv;
	for(int i = l;i <= mid;i++){
		if(ev[i].op == 1)uu.push_back(ev[i]);
	}
	for(int i = mid + 1;i <= r;i++){
		if(ev[i].op == 2)vv.push_back(ev[i]);
	}
	vector<NODE> inp;
	merge(all(uu), all(vv), back_inserter(inp));
	get_st(inp);
	deleteops();

	// return;
	merge(ev + l, ev + mid + 1, ev + mid + 1, ev + r + 1, tp);
	for(int i = l;i <= r;i++){
		ev[i] = tp[i - l];
	}
	return;
}

// given some queries:
// 1. add a point (x, y) in map(range in 1e6 * 1e6)
// 2. answer the nearest distance between an added point and the given point (x, y)
// CQD divide and conquer
void sol(){
	rep(i,300005)ans[i] = inf;
	// input
	ll cc = 0;
	cin>>n>>m;
	ll nn = n + m;
	rep(i,n){
		cin>>x>>y;
		ve[cc] = {1, x, y, pcnt};
		cc++;
		pcnt++;
	}
	rep(i,m){
		ll op;cin>>op>>x>>y;
		if(op == 1){
			ve[cc] = {1, x, y, pcnt};
			cc++;
			pcnt++;
		}
		else{
			ve[cc] = {2, x, y, qcnt};
			cc++;
			qcnt++;
		}
	}
	// 1
	rep(i,nn)ev[i] = ve[i];
	CDQ(0, nn - 1);
	// 2
	rep(i,nn)rotate(ve[i]);
	rep(i,nn)ev[i] = ve[i];
	CDQ(0, nn - 1);
	// 3
	rep(i,nn)rotate(ve[i]);
	rep(i,nn)ev[i] = ve[i];
	CDQ(0, nn - 1);
	// 4
	rep(i,nn)rotate(ve[i]);
	rep(i,nn)ev[i] = ve[i];
	CDQ(0, nn - 1);

	// output
	rep(i,qcnt){
		cend(ans[i]);
	}
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
