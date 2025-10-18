//Codeforces Round 909 (Div. 3) G

#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)
#define rep01n(i, n) for (int i = 0; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)

#define csp(n) cout << n << " "
#define cend(n) cout << n << endl
#define cendl cout << endl

typedef long long ll;
const ll mod = 998244353;
const ll p = mod;
using namespace std;

ll t;
ll n,k,c,m,q;

ll perm[200005];

ll tin[200005];
ll tout[200005];

vector<ll> g[200005];

ll timer = 0;

 
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
 
struct SegmentTree {
    int n;
    vector<vector<int>> tree;
 
    void build(vector<int> &a, int x, int l, int r) {
        if (l + 1 == r) {
            tree[x] = {a[l]};
            return;
        }
 
        int m = (l + r) / 2;
        build(a, 2 * x + 1, l, m);
        build(a, 2 * x + 2, m, r);
        merge(all(tree[2 * x + 1]), all(tree[2 * x + 2]), back_inserter(tree[x]));
    }
 
    SegmentTree(vector<int>& a) : n(a.size()) {
        int SIZE = 1 << (__lg(n) + bool(__builtin_popcount(n) - 1));
        tree.resize(2 * SIZE - 1);
        build(a, 0, 0, n);
    }
 
    int count(int lq, int rq, int mn, int mx, int x, int l, int r) {
        if (rq <= l || r <= lq) return 0;
        if (lq <= l && r <= rq) return lower_bound(all(tree[x]), mx) - lower_bound(all(tree[x]), mn);
 
        int m = (l + r) / 2;
        int a = count(lq, rq, mn, mx, 2 * x + 1, l, m);
        int b = count(lq, rq, mn, mx, 2 * x + 2, m, r);
        return a + b;
    }
 
    int count(int lq, int rq, int mn, int mx) {
        return count(lq, rq, mn, mx, 0, 0, n);
    }
};


void dfs(ll x, ll fa){
	tin[x] = timer;
	timer++;
	for(auto ad : g[x]){
		if(ad != fa){
			dfs(ad, x);
		}
	}
	tout[x] = timer;
}
void sol(){
	timer = 0;
	cin>>n>>q;
	
	vector<int> a(n);
	
	rep(i,n+5){
		g[i].clear();
	}
	rep(i,n-1){
		ll x,y;cin>>x>>y;
		x--;y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	
	dfs(0, -1);
	rep(i,n){
		cin>>perm[i];
	}
	rep(i,n)a[i] = tin[perm[i] - 1];
	
	SegmentTree ST(a);
	for (int i = 0; i < q; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        l--; x--;
        if (ST.count(l, r, tin[x], tout[x])) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}
int main() {
	cin>>t;
	while(t--)sol();
	return 0;
}
