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
// just init it as 1,2,...n via insert
class Treap{
private:
	class Node{
	public:
		ll val, pri, sz; // in this problem, value is just an indicator of index
		Node *le, *ri;
		bool flip;
		Node(ll pa_val, ll pa_pri)
            : val(pa_val), pri(pa_pri), sz(1), le(nullptr), ri(nullptr), flip(false) {}
		Node(ll pa_val, ll pa_pri, Node* pa_le, Node* pa_ri)
            : val(pa_val), pri(pa_pri), sz(1), le(pa_le), ri(pa_ri), flip(false) {
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
		if (cur->flip) {
			if (cur->le) cur->le->flip = !cur->le->flip;
			if (cur->ri) cur->ri->flip = !cur->ri->flip;
			swap(cur->le, cur->ri);
			cur->flip = false;
		}
	}
	pair<Node*, Node*> split_by_size(Node* cur, ll size){
		// split : 1(sz = size), 2(remain)
		if (cur == nullptr) return {nullptr, nullptr};

		// flip mark
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

		// flip mark
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
	void _clear(Node* cur){
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
	vll _output(Node* cur, vll & ans){
		if (cur != nullptr) {
			if (cur->flip) {
				_output(cut->ri, ans);
				ans.push_back(cur->val);
				_output(cut->le, ans);
			}
			else {
				_output(cut->le, ans);
				ans.push_back(cur->val);
				_output(cut->ri, ans);
			}
		}
	}

public:
	void clear(){
		_clear(root);
		root = nullptr;
	}
	ll size(){
		return root == nullptr ? 0 : root->sz;
	}
	void insert(ll val){
		return _insert(val);
	}
	vll output(){
		vll ans;
		return _output(root, ans);
	}
	void reverse(ll l, ll r){
		// l and r >= 1
		auto [tp, r] = split_by_size(root, r);
		auto [l, tar] = split_by_size(tp, l - 1);
		tar->flip = !tar->flip;
		root = merge(merge(l, tar), r);
	}
};

int main(){
    cin>>n>>m;
	Treap treap;
	rep1n(i,n){
		treap.insert(i);
	}
	rep1n(i,m){
		ll x, y;
		cin>>x>>y;
	}
	auto ans = treap.output();
	for(auto o : ans){
		csp(o);
	}
	return 0;
}
