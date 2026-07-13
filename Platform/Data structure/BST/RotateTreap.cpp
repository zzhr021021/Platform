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

// Treap, every node has its val and priority, using min heap as priority
// there are rotating treap and non-rotating treap, this is the implementation of the former
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
	constexpr static ll NIL = -1; // query node not exist

	Node* newNode(ll val){
		return new Node(val, rnd());
	}
	void _clear(Node* cur){
		if (cur == nullptr) return;
		_clear(cur->le);
		_clear(cur->ri);
		delete cur;
	}
	void _rotate_le(Node* & rt){
		// this makes the root the son of its right son
		if (rt == nullptr || rt->ri == nullptr) return;
		Node* ri = rt->ri;
		
		rt->ri = ri->le;
		ri->le = rt;
		rt->update();
		ri->update();
		rt = ri;
	}
	void _rotate_ri(Node* & rt){
		// this makes the root the son of its left son
		if (rt == nullptr || rt->le == nullptr) return;
		Node* le = rt->le;

		rt->le = le->ri;
		le->ri = rt;
		rt->update();
		le->update();
		rt = le;
	}
	void _insert(Node* & cur, ll val){
		if (cur == nullptr) {
			// no node
			cur = newNode(val);
		}
		else if (val == cur->val){
			// same value
			cur->cnt++;
			cur->sz++;
		}
		else if (val < cur->val) {
			// less than
			_insert(cur->le, val);
			if (cur->le->pri < cur->pri) {
				_rotate_ri(cur);
			}
			cur->update();
		}
		else {
			// greater than
			_insert(cur->ri, val);
			if (cur->ri->pri < cur->pri) {
				_rotate_le(cur);
			}
			cur->update();
		}
	}
	bool _erase(Node* & cur, ll val){
		if (_find(cur, val) == 0){
			return false;
		}
		if (val > cur->val) {
			_erase(cur->ri, val);
			cur->update();
		}
		else if (val < cur->val){
			_erase(cur->le, val);
			cur->update();
		}
		else {
			Node *tmp = cur;
			if (cur->cnt > 1) {
				// has repetition
				cur->cnt--;
				cur->sz--;
			}
			else if (cur->le == nullptr && cur->ri == nullptr) {
				delete cur;
				cur = nullptr;
			}
			else if (cur->le == nullptr) {
				cur = tmp->ri;
				delete tmp;
			}
			else if (cur->ri == nullptr) {
				cur = tmp->le;
				delete tmp;
			}
			else {
				if (cur->le->pri < cur->ri->pri) {
					_rotate_ri(cur);
					_erase(cur->ri, val);
				}
				else {
					_rotate_le(cur);
					_erase(cur->le, val);
				}
				cur->update();
			}
		}
		return true;
	}
	ll _find(Node* & cur, ll val){
		if (cur == nullptr) return 0;
		else if (cur->val == val) {
			return cur->cnt;
		}
		else if (cur->val > val){
			return _find(cur->le, val);
		}
		else {
			return _find(cur->ri, val);
		}
	}
	ll _kth(Node* & cur, ll k){
		ll lesz = cur->le == nullptr ? 0 : cur->le->sz;
		ll curcnt = cur->cnt;
		if (lesz >= k) {
			return _kth(cur->le, k);
		}
		else if (lesz + curcnt >= k){
			return cur->val;
		}
		else {
			return _kth(cur->ri, k - lesz - curcnt);
		}
	}
	ll _rank(Node* & cur, ll val){
		if (cur == nullptr){
			return 0;
		}
		ll cnt = 0;
		ll lesz = cur->le == nullptr ? 0 : cur->le->sz;
		if (cur->val == val) {
			cnt = lesz;
		}
		else if (cur->val > val) {
			cnt = _rank(cur->le, val);
		}
		else {
			cnt = _rank(cur->ri, val) + lesz + cur->cnt;
		}
		return cnt;
	}
	ll _query_prev(Node* cur, ll val){
		ll ans = NIL;
		while (cur != nullptr) {
			if (cur->val < val) {
				ans = cur->val;
				cur = cur->ri;
			}
			else {
				cur = cur->le;
			}
		}
		return ans;
	}
	ll _query_next(Node* cur, ll val){
		ll ans = NIL;
		while (cur != nullptr) {
			if (cur->val > val) {
				ans = cur->val;
				cur = cur->le;
			}
			else {
				cur = cur->ri;
			}
		}
		return ans;
	}
public:
	void clear(){
		_clear(root);
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
		return _insert(root, val);
	}
	bool erase(ll val){
		return _erase(root, val);
	}
	ll find(ll val){
		// return cnt
		return _find(root, val);
	}
	ll kth(ll k){
		// make sure k <= sz
		return _kth(root, k);
	}
	ll rank(ll val){
		// return the cnt of x that x < val, plus one
		return _rank(root, val) + 1;
	}
	ll query_prev(ll val){
		// return the first node(value) that less than val
		return _query_prev(root, val);
	}
	ll query_next(ll val){
		// return the first node(value) that greater than val
		return _query_next(root, val);
	}
};

int main(){
    
	return 0;
}
