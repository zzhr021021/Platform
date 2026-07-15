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

class Treap{
public:
	class Node{
	public:
		// sz is the size of subtree
		ll val, pri, sz;
		Node *le, *ri, *fa;
		Node(ll pa_val, ll pa_pri)
            : val(pa_val), pri(pa_pri), sz(1), le(nullptr), ri(nullptr), fa(nullptr) {}
		Node(ll pa_val, ll pa_pri, Node* pa_le, Node* pa_ri)
            : val(pa_val), pri(pa_pri), sz(1), le(pa_le), ri(pa_ri), fa(nullptr) {
			update();
		}
		void update() {
			sz = 1;
			if (le != nullptr) sz += le->sz;
			if (ri != nullptr) sz += ri->sz;
		}
	};
	Node* root = nullptr;
	mt19937_64 rnd;
	constexpr static ll NIL = -1; // query node not exist

	Node* newNode(ll val){
		return new Node(val, rnd());
	}
	pair<Node*, Node*> split(Node* cur, ll key){
		// split : 1(... , key] , 2(key, ...)
		if (cur == nullptr) return {nullptr, nullptr};
		if (cur->val <= key) {
			pair<Node*, Node*> pa = split(cur->ri, key);
			cur->ri = pa.first;
            if(cur->ri != nullptr)cur->ri->fa = cur;
			cur->update();
			return {cur, pa.second};
		}
		else {
			pair<Node*, Node*> pa = split(cur->le, key);
			cur->le = pa.second;
            if(cur->le != nullptr)cur->le->fa = cur;
			cur->update();
			return {pa.first, cur};
		}
	}
	tuple<Node*, Node*, Node*> split_by_rank(Node* cur, ll rk){
		// split : 1(... , rk), 2[rk](only node) 3(rk, ...)
		if (cur == nullptr) return {nullptr, nullptr, nullptr};
		ll lsize = cur->le == nullptr ? 0 : cur->le->sz;
		if (rk <= lsize) {
			Node *l, *mid, *r;
			tie(l, mid, r) = split_by_rank(cur->le, rk);
			cur->le = r;
            if(r != nullptr)r->fa = cur;
			cur->update();
			return {l, mid, cur};
		}
		else if (rk <= lsize + 1) {
			Node *tpl = cur->le;
			Node *tpr = cur->ri;
			cur->le = cur->ri = nullptr;
			cur->update();
			return {tpl, cur, tpr};
		}
		else {
			Node *l, *mid, *r;
			ll minu = lsize + 1;
			tie(l, mid, r) = split_by_rank(cur->ri, rk - minu);
			cur->ri = l;
            if(l != nullptr)l->fa = cur;
			cur->update();
			return {cur, mid, r};
		}
	}
	Node* merge(Node* u, Node* v){
		if (u == nullptr && v == nullptr) return nullptr;
		if (u == nullptr) return v;
		if (v == nullptr) return u;
		if (u->pri < v->pri) {
			u->ri = merge(u->ri, v);
            u->ri->fa = u;
            u->fa = nullptr;
			u->update();
			return u;
		}
		else {
			v->le = merge(u, v->le);
            v->le->fa = v;
            v->fa = nullptr;
			v->update();
			return v;
		}
	}

	Node* _insert(ll val){
		auto [temp, tri] = split(root, val);
		auto [tle, tar] = split(temp, val - 1);
		Node * newnode;
        newnode = newNode(val);
		auto comb = merge(tle, tar == nullptr ? newnode : tar);
		root = merge(comb, tri);
        return newnode;
	}
	ll _kth(Node* cur, ll k){
		auto [tle, tar, tri] = split_by_rank(cur, k);
		ll ret = tar->val;
		root = merge(merge(tle, tar), tri);
		return ret;
	}
	ll _rank(Node* cur, ll val){
		auto [tle, tri] = split(cur, val - 1);
		ll ret = (tle == nullptr ? 0 : tle->sz) + 1;
		root = merge(tle, tri);
		return ret;
	}
    tuple<Node*, Node*, Node*> split_by_pointer(Node* finalNode){
        // smartly use sz
        ll sz = 1;
        sz += finalNode->le == nullptr ? 0 : finalNode->le->sz;
        Node* cur = finalNode;
        while(cur != root){
            if(cur == cur->fa->ri){
                sz += 1;
                sz += cur->fa->le == nullptr ? 0 : cur->fa->le->sz;
            }
            cur = cur->fa;
        }
        
        return split_by_rank(root, sz);
    }

public:
    // permutation pointers
    Node* nodes[200005];
	ll size(){
		return root == nullptr ? 0 : root->sz;
	}
	Node* insert(ll val){
        return _insert(val);
	}
	ll kth(ll k){
		// make sure k <= sz
		return _kth(root, k);
	}
	ll rank(ll val){
		// return the count of x that x < val, plus one
		return _rank(root, val);
	}
    // problem
    void query_top(ll num){
        auto [tpl, tar, tpr] = split_by_pointer(nodes[num]);
        root = merge(merge(tar, tpl), tpr);
    }
    void query_bottom(ll num){
        auto [tpl, tar, tpr] = split_by_pointer(nodes[num]);
        root = merge(merge(tpl, tpr), tar);
    }
    void query_insert(ll num, ll dir){
        if(dir == 0){
            return;
        }
        auto [tpl, tar, tpr] = split_by_pointer(nodes[num]);
        // ensured
        if(dir == -1){
            ll sz = tpl->sz;
            auto [ttpl, ttar, ttpr] = split_by_rank(tpl, sz);
            root = merge(merge(ttpl, tar), merge(ttar, tpr));
        }
        else if(dir == 1){
            ll sz = tpr->sz;
            auto [ttpl, ttar, ttpr] = split_by_rank(tpr, 1);
            root = merge(merge(tpl, ttar), merge(tar, ttpr));
        }
    }
    ll query_ask(ll num){
        auto [tpl, tar, tpr] = split_by_pointer(nodes[num]);
        ll ret = tpl == nullptr ? 0 : tpl->sz;
        root = merge(merge(tpl, tar), tpr);
        return ret;
    }
    ll query_query(ll num){
        auto [tpl, tar, tpr] = split_by_rank(root, num);
        ll ret = tar->val;
        root = merge(merge(tpl, tar), tpr);
        return ret;
    }

    // debug
    void output(Node* cur){
        if(cur == nullptr){
            return;
        }
        output(cur->le);
        csp(cur->val);
        output(cur->ri);
    }
};

void sol(){
    cin>>n>>m;
    Treap treap;
    rep1n(i,n){
        // actually the i, value is not use
        cin>>a[i];
        auto o = treap.insert(i);
        treap.nodes[a[i]] = o;
    }
    rep1n(i,n){
        treap.nodes[a[i]]->val = a[i];
    }

    rep1n(i,m){
        string s;cin>>s>>x;
        if(s == "Top"){
            treap.query_top(x);
        }
        else if(s == "Bottom"){
            treap.query_bottom(x);
        }
        else if(s == "Insert"){
            cin>>y;
            treap.query_insert(x, y);
        }
        else if(s == "Ask"){
            cend(treap.query_ask(x));
        }
        else{
            cend(treap.query_query(x));
        }

        // ctest;treap.output(treap.root);cendl;
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