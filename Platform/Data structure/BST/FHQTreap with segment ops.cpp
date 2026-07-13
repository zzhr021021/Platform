#include<bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define rep1(i, n) for (ll i = 1; i < (n); ++i)
#define rep1n(i, n) for (ll i = 1; i <= (n); ++i)
#define rep01n(i, n) for (ll i = 0; i <= (n); ++i)
#define repr(i, n) for (ll i = (n) - 1; i >= 0; --i)
#define csp(n) cout << n << " ";
#define cend(n) cout << n << endl;
#define cendl cout << endl;

#define ll long long

#define vll vector<ll>

const ll MOD = 1e9+7;
const ll p = MOD;
using namespace std;

ll n,m,t,k;

// FHQ Treap with segment operations
// this flip is segmentation, for Luogu P3391
class Treap{
private:
	class Node{
	public:
		ll val, pri, cnt, sz;
		Node *le, *ri;
		Node(ll pa_val, ll pa_pri)
            : val(pa_val), pri(pa_pri), cnt(1), sz(1), le(nullptr), ri(nullptr) {}
		Node(ll pa_val, ll pa_pri, Node* pa_le, Node* pa_ri)
            : val(pa_val), pri(pa_pri), cnt(1), sz(1), le(pa_le), ri(pa_ri) {
			update();
		}
		void update() {
			// update sz and cnt
			sz = cnt;
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
	tuple<Node*, Node*, Node*> split_by_rank(Node* cur, ll rk){
		// split : 1(... , rk), 2[rk](only node) 3(rk, ...)
		if (cur == nullptr) return {nullptr, nullptr, nullptr};
		ll lsize = cur->le == nullptr ? 0 : cur->le->sz;
		if (rk <= lsize) {
			Node *l, *mid, *r;
			tie(l, mid, r) = split_by_rank(cur->le, rk);
			cur->le = r;
			cur->update();
			return {l, mid, cur};
		}
		else if (rk <= lsize + cur->cnt) {
			Node *tpl = cur->le;
			Node *tpr = cur->ri;
			cur->le = cur->ri = nullptr;
			cur->update();
			return {tpl, cur, tpr};
		}
		else {
			Node *l, *mid, *r;
			ll minu = lsize + cur->cnt;
			tie(l, mid, r) = split_by_rank(cur->ri, rk - minu);
			cur->ri = l;
			cur->update();
			return {cur, mid, r};
		}
	}
	Node* merge(Node* u, Node* v){
		// make sure all val in u are less than any val in v
		if (u == nullptr && v == nullptr) return nullptr;
		if (u == nullptr) return v;
		if (v == nullptr) return u;
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

	void clear(Node* cur){
		if (cur == nullptr) return;
		clear(cur->le);
		clear(cur->ri);
		delete cur;
	}
	void _insert(ll val){
		auto [temp, tri] = split(root, val);
		auto [tle, tar] = split(temp, val - 1);
		Node * newnode;
		if (tar == nullptr) {
			newnode = newNode(val);
		}
		else {
			tar->cnt++;
			tar->update();
		}
		auto comb = merge(tle, tar == nullptr ? newnode : tar);
		root = merge(comb, tri);
	}
	bool _erase(ll val){
		auto [temp, tri] = split(root, val);
		auto [tle, tar] = split(temp, val - 1);
		if (tar == nullptr) {
			root = merge(tle, tri);
			return false;
		}
		if (tar->cnt > 1) {
			tar->cnt--;
			tar->update();
			root = merge(merge(tle, tar), tri);
		}
		else {
			delete tar;
			root = merge(tle, tri);
		}
		return true;
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
	ll _query_prev(ll val){
		auto [tle, tri] = split(root, val - 1);
		if (tle == nullptr) return NIL;
		ll ret = _kth(tle, tle->sz);
		root = merge(tle, tri);
		return ret;
	}
	ll _query_next(ll val){
		auto [tle, tri] = split(root, val);
		if (tri == nullptr) return NIL;
		ll ret = _kth(tri, 1);
		root = merge(tle, tri);
		return ret;
	}

public:
	void clear(){
		clear(root);
		root = nullptr;
	}
	ll size(){
		return root == nullptr ? 0 : root->sz;
	}
	void init(vll ve){
		// O(nlogn)
		clear();
		for(ll o : ve){
			insert(o);
		}
		// TODO : implement O(n) init function
	}
	void init(ll a[], ll st, ll len){
		clear();
		for(ll i = st;i <= st + len - 1;i++){
			insert(a[i]);
		}
	}
	void insert(ll val){
		return _insert(val);
	}
	bool erase(ll val){
		return _erase(val);
	}
	ll kth(ll k){
		// make sure k <= sz
		return _kth(root, k);
	}
	ll rank(ll val){
		// return the cnt of x that x < val, plus one
		return _rank(root, val);
	}
	ll query_prev(ll val){
		return _query_prev(val);
	}
	ll query_next(ll val){
		return _query_next(val);
	}
	void flip(){
		
	}
};

int main(){
    
	return 0;
}
