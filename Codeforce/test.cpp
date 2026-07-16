#include<bits/stdc++.h>
#define debug(x) cout << #x << " = " << x << endl
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (ll i = 1; i <= (n); ++i)
#define rep1nr(i, n) for (int i = (n); i >= 1; --i)
#define rep01n(i, n) for (int i = 0; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define replr(i, l, r) for (int i = l;i <= r;i++)
#define repij(i, j, n, m) for (int i = 0; i < (n); ++i) for (int j = 0; j < (m); ++j)

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
#define bob cout<<"Bob\n"
#define alice cout<<"Alice\n"
#define csp(n) cout << n << " "
#define cend(n) cout << n << endl
#define cendl cout << endl
#define ctest cout << "test   "
#define cgap cout << "--------------------" << endl
#define pb push_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

#define alice cout<<"Alice\n"
#define bob cout<<"Bob\n"
#define draw cout<<"Draw\n"

const ll MOD = 1e9 + 7;
const ll MODD = 1e9 + 9;
const ll MOOD = 998244353;
ll p = MOOD;
const ll inf = 1e18;
const ll INF = 1e18;
const ll N = 200500;
// ll dix[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
// ll diy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
using namespace std;


void ckmax(ll & x, ll y){
    if(y > x)x = y;
}
void ckmin(ll & x, ll y){
    if(y < x)x = y;
}
void printvec(vll & v){
    for(auto o : v){
        csp(o);
    }
    cendl;
}
ll tt, ttt;
ll n,k,m,t,x,y,z,h,q,d,s;

ll a[200050];
ll b[200050];

void md(ll & x){
    x = (x + p) % p;
}

ll ladder(ll x){
    return (1 + x) * x / 2;
}
ll sq(ll x){
    return x * x;
}
ll qpow(ll x, ll y){
    ll ans = 1;
    while(y){
        if(y&1) ans = ans * x % p;
        x = x * x % p,y>>=1;
    }
    return ans;
}

struct Vals{
        ll sum, suml, sumr, summax;
    };
Vals merge_vals(const Vals & u, const Vals & v){
    Vals ret;
    ret.sum = u.sum + v.sum;
    ret.suml = max(u.suml, u.sum + v.suml);
    ret.sumr = max(v.sumr, u.sumr + v.sum);
    ret.summax = max(u.summax, v.summax);
    ckmax(ret.summax, u.sumr + v.suml);
    return ret;
}
Vals single_val(ll val){
    Vals ret;
    ret.sum = val;
    if(val > 0){
        ret.suml = ret.sumr = ret.summax = val;
    }
    return ret;
}
static Vals ZEROVAL = {0,0,0,0};
class Treap{
public:
	class Node{
	public:
		ll val, pri;
        ll sz;
        Vals vals;
		Node *le, *ri;
        // lazy
		bool flip, change;
        ll changenum;
		Node(ll pa_val, ll pa_pri)
            : val(pa_val), pri(pa_pri), sz(1), le(nullptr), ri(nullptr), 
            flip(false), change(false) 
        {
            if (pa_val > 0) {
                this->vals = {pa_val, pa_val, pa_val, pa_val};
            }
            else {
                this->vals = {pa_val, 0,0,0};
            }
        }
		Node(ll pa_val, ll pa_pri, Node* pa_le, Node* pa_ri)
            : val(pa_val), pri(pa_pri), sz(1), le(pa_le), ri(pa_ri), 
            flip(false), change(false) 
        {
			update();
		}
        // pushdown before update
		void update() {
			sz = 1;
            vals = single_val(val);
			if (le != nullptr) {
                sz += le->sz;
                vals = merge_vals(le->vals, vals);
            }
			if (ri != nullptr) {
                sz += ri->sz;
                vals = merge_vals(vals, ri->vals);
            }
		}
	};

	Node* root = nullptr;
	mt19937_64 rnd;

	Node* newNode(ll val){
		return new Node(val, rnd());
	}
	pair<Node*, Node*> split(Node* cur, ll key){
		// split : 1(... , key] , 2(key, ...)
		if (cur == nullptr) return {nullptr, nullptr};
		if (cur->val <= key) {
			pair<Node*, Node*> pa = split(cur->ri, key);
			cur->ri = pa.first;
			cur->update();
			return {cur, pa.second};
		}
		else {
			pair<Node*, Node*> pa = split(cur->le, key);
			cur->le = pa.second;
			cur->update();
			return {pa.first, cur};
		}
	}
	void pushdown(Node* cur){
        Vals vals;
        if (cur->change) {
            ll cn = cur->changenum;
            cur->val = cn;
            cur->vals.sum = cn * cur->sz;
            if (cn > 0) {
                cur->vals.suml = cur->vals.sumr = cur->vals.summax = cn * cur->sz;
            }
            else {
                cur->vals.suml = cur->vals.sumr = cur->vals.summax = 0;
            }
        }
        if (cur->flip) {
            swap(cur->vals.suml, cur->vals.sumr);
        }
		if (cur->flip) {
			if (cur->le) cur->le->flip = !cur->le->flip;
			if (cur->ri) cur->ri->flip = !cur->ri->flip;
			swap(cur->le, cur->ri);
			cur->flip = false;
		}
        if (cur->change) {
            if (cur->le) {
                cur->le->change = true;
                cur->le->changenum = cur->changenum;
            }
			if (cur->ri) {
                cur->ri->change = true;
                cur->ri->changenum = cur->changenum;
            }
			cur->change = false;
        }
	}
	pair<Node*, Node*> split_by_size(Node* cur, ll size){
		// split : 1(sz = size), 2(remain)
		if (cur == nullptr) return {nullptr, nullptr};

		// lazy mark
		pushdown(cur);
		
		ll lsize = cur->le == nullptr ? 0 : cur->le->sz;
		if (size <= lsize) {
			auto [l, r] = split_by_size(cur->le, size);
			cur->le = r;
			cur->update();
			return {l, cur};
		}
		else {
			ll minu = lsize + 1;
			auto [l, r] = split_by_size(cur->ri, size - minu);
			cur->ri = l;
			cur->update();
			return {cur, r};
		}
	}
	Node* merge(Node* u, Node* v){
		if (u == nullptr && v == nullptr) return nullptr;
		if (u == nullptr) return v;
		if (v == nullptr) return u;
        
        ctest;ctest;ctest;csp(u->val);csp(v->val);cendl;
		// lazy mark
		pushdown(u);
		pushdown(v);

		if (u->pri < v->pri) {
			u->ri = merge(u->ri, v);
			u->update();
			return u;
		}
		else {
			v->le = merge(u, v->le);
			v->update();
			return v;
		}
	}
	void _insert(ll val){
		auto [temp, tri] = split(root, val);
		auto [tle, tar] = split(temp, val - 1);
		Node * newnode;
        newnode = newNode(val);
		auto comb = merge(tle, tar == nullptr ? newnode : tar);
		root = merge(comb, tri);
	}
    Node* _push_back(Node* cur, ll val){
        return merge(cur, newNode(val));
    }

public:
	ll size(){
		return root == nullptr ? 0 : root->sz;
	}
	void insert(ll val){
		_insert(val);
	}
    void push_back(ll val){
        root = _push_back(root, val);
    }
	void reverse(ll l, ll r){
		// l and r >= 1
		auto [tp, tpr] = split_by_size(root, r);
		auto [tpl, tar] = split_by_size(tp, l - 1);
		tar->flip = !tar->flip;
		root = merge(merge(tpl, tar), tpr);
	}

    void output(Node * cur){
        if (cur == nullptr) return;
        pushdown(cur);
        output(cur->le);
        csp(cur->val);
        output(cur->ri);
    }

    // problem
    void query_insert(ll pos, vll ve){
        auto [tpl, tpr] = split_by_size(root, pos);
        for(auto o : ve){
            _push_back(tpl, o);
            ctest;cend(o);
            output(tpl);ctest;csp(tpl->sz);
            cendl;
        }
        root = merge(tpl, tpr);
    }
    void query_delete(ll pos, ll tot){
        auto [tpl, tpr] = split_by_size(root, pos - 1);
        auto [tpll, tprr] = split_by_size(tpr, tot);
        root = merge(tpl, tprr);
    }
    void query_make_same(ll pos, ll tot, ll c){
        auto [tpl, tpr] = split_by_size(root, pos - 1);
        auto [tpll, tprr] = split_by_size(tpr, tot);
        tpll->change = true;
        tpll->changenum = c;
        root = merge(merge(tpl, tpll), tprr);
    }
    void query_reverse(ll pos, ll tot){
        auto [tpl, tpr] = split_by_size(root, pos - 1);
        auto [tpll, tprr] = split_by_size(tpr, tot);
        tpll->flip = true;
        root = merge(merge(tpl, tpll), tprr);
    }
    ll query_get_sum(ll pos, ll tot){
        auto [tpl, tpr] = split_by_size(root, pos - 1);
        auto [tpll, tprr] = split_by_size(tpr, tot);

        pushdown(tpll);
        ll ret = tpll->vals.sum;
        root = merge(merge(tpl, tpll), tprr);
        return ret;
    }
    ll query_max_sum(){
        pushdown(root);
        ll ret = root->vals.summax;
        return ret;
    }
};

void sol(){
    Treap treap;
    cin>>n>>m;
    rep1n(i,n){
        cin>>x;
        treap.push_back(x);
    }
    rep1n(i,m){
        ctest;
        treap.output(treap.root);
        ctest;csp(treap.root->sz);
        cendl;

        string s;cin>>s;
        ll pos, tot, c, ans;
        if (s == "INSERT") {
            cin>>pos>>tot;
            vll toadd;
            rep1n(j,tot){
                cin>>x;
                toadd.push_back(x);
            }
            treap.query_insert(pos, toadd);
        }
        else if (s == "DELETE") {
            cin>>pos>>tot;
            treap.query_delete(pos, tot);
        }
        else if (s == "MAKE-SAME") {
            cin>>pos>>tot>>c;
            treap.query_make_same(pos, tot, c);
        }
        else if (s == "REVERSE") {
            cin>>pos>>tot;
            treap.query_reverse(pos, tot);
        }
        else if (s == "GET-SUM") {
            cin>>pos>>tot;
            ans = treap.query_get_sum(pos, tot);
            cend(ans);
        }
        else {
            ans = treap.query_max_sum();
            cend(ans);
        }
    }
}

ll tnt(){
    while(1){
    }
    return 0;
}


int main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);

    tt = 1;
    // cin>>tt;
    for(ttt = 1;ttt <= tt;ttt++){
        sol();
    }
    system("pause");
    return 0;
}