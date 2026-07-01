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

// Treap, every node has its val and priority
// there are rotating treap and non-rotating treap, this is the implementation of the former
// insert, erase, find, rank, kth, predecessor, successor
// rank(x) : count the number of y that y < x in treap
class Treap{
private:
	class Node{
	public:
		// cnt is the repeat count
		// sz is the size of subtree
		ll val, pri, cnt, sz;
		Node* le, ri, fa;
		Node(ll pa_val, ll pa_pri)
            : val(pa_val), pri(pa_pri), le(nullptr), ri(nullptr), fa(nullptr) {}
		Node(ll pa_val, ll pa_pri, Node* pa_le, Node* ri_le, Node* fa_le)
            : val(pa_val), pri(pa_pri), le(pa_le), ri(ri_le), fa(fa_le) {}
		void update(){
			// update sz and cnt
			sz = cnt;
			if (le != nullptr) sz += le->sz;
			if (ri != nullptr) sz += ri->sz;
		}
	};
	int n;
	Node* root = nullptr;
	mt19937_64 rnd;

	Node* newNode(ll val){
		return new Node(val, rnd());
	}

	void rotate_le(Node* rt){
		// this makes the root the son of its right son
		
	}
	void rotate_ri(Node* rt){
		// this makes the root the son of its left son

	}
public:
	ll size(){
		return n;
	}
	void init(vll ve){

	}
	void insert(ll val){
		
	}
	bool find(ll val){

	}
	bool erase(ll val){

	}
	ll kth(ll k){

	}
	ll rank(ll val){

	}
};

int main(){
    
	return 0;
}
