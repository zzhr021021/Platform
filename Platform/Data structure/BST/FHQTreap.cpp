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

// FHQ Treap(non-rotation treap), every node has its val and priority, using min heap as priority
// there are rotating treap and non-rotating treap, this is the implementation of the latter
// insert, erase, find, rank, kth, query_prev, query_next 
// rank(x) : count the number of y that y < x in treap
class Treap{
private:
	class Node{
	public:
		// cnt is the repeat count
		// sz is the size of subtree
		ll val, pri, cnt, sz;
		Node *le, *ri;
		Node(ll pa_val, ll pa_pri)
            : val(pa_val), pri(pa_pri), cnt(1), sz(1), le(nullptr), ri(nullptr) {}
		Node(ll pa_val, ll pa_pri, Node* pa_le, Node* pa_ri)
            : val(pa_val), pri(pa_pri), cnt(1), sz(1), le(pa_le), ri(pa_ri) {
			update();
		}
		void update(){
			// update sz and cnt
			sz = cnt;
			if (le != nullptr) sz += le->sz;
			if (ri != nullptr) sz += ri->sz;
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
		else{
			pair<Node*, Node*> pa = split(cur->le, key);
			cur->le = pa.second;
			cur->update();
			return {pa.first, cur};
		}
	}
	tuple<Node*, Node*, Node*> split_by_rank(Node* cur, ll rk){
		// split : 1(... , rk), 2[rk](only node) 3(rk, ...)
		
		if (cur == nullptr) return {nullptr, nullptr};
		if (cur->val <= key) {
			pair<Node*, Node*> pa = split(cur->ri);
			cur->ri = pa.first;
			cur->update();
			return {cur, pa.second};
		}
		else{
			pair<Node*, Node*> pa = split(cur->le);
			cur->le = pa.second;
			cur->update();
			return {pa.first, cur};
		}
	}
	void clear(Node* cur){
		if (cur == nullptr) return;
		clear(cur->le);
		clear(cur->ri);
		delete cur;
	}
	void insert(Node* & cur, ll val){
	}
	bool erase(Node* & cur, ll val){
	}
	ll find(Node* & cur, ll val){
	}
	ll kth(Node* & cur, ll k){
	}
	ll rank(Node* & cur, ll val){
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
		clear();
		for(ll o : ve){
			insert(o);
		}
	}
	void init(ll a[], ll st, ll len){
		clear();
		for(ll i = st;i <= st + len - 1;i++){
			insert(a[i]);
		}
	}
	void insert(ll val){
		return insert(root, val);
	}
	bool erase(ll val){
		return erase(root, val);
	}
	ll find(ll val){
		// return cnt
		return find(root, val);
	}
	ll kth(ll k){
		// make sure k <= sz
		return kth(root, k);
	}
	ll rank(ll val){
		// return the cnt of x that x < val, plus one
		return rank(root, val) + 1;
	}
};

int main(){
    
	return 0;
}
