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
#define smpq priority_queue<long long, vector<long long>, greater<long long>>
#define bgpq priority_queue<long long> 


#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define csp(n) cout << n << " "
#define cend(n) cout << n << endl
#define cendl cout << endl
#define ctest cout << "test   "
#define pb push_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
 
#define alice cout<<"Alice\n"
#define bob cout<<"Bob\n"
#define draw cout<<"Draw\n"

const ll MOD = 1e9+7;
const ll MODD = 1e9+9;
const ll MOOD = 998244353;
ll p = MOD;
const ll inf = 1e18;
const ll INF = 1e18; 
const int N = 200005;
using namespace std;
 
ll tt;
ll ttt;
ll n,k,m,d,q,t,x,y,z,h;
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

void printvec(vll & v){
	for(ll &x : v){
		cout << x << " ";
	}
	cendl;
}


// Luogu P3808, Aho-Corasick Automaton
// this is without topo version
struct Trie{
    ll val = 0; // reserve?
    ll dep = 0;
    ll ind = 0;
    Trie * ptr[26];
    Trie * fail;
    ll appear;
    Trie(){
        val = dep = 0;
        rep(i,26){
            ptr[i] = nullptr;
        }
        fail = nullptr;
        appear = 0;
    }

};

void addString(Trie * rt_trie, string & s, ll ind){
    Trie * curr = rt_trie;
    ll sn = s.size();
    rep(i,sn){
        Trie * fa = curr;
        ll ind = s[i] - 'a';
        if(curr->ptr[ind] == nullptr){
            Trie * node = new Trie();
            curr->ptr[ind] = node;
        }
        curr = curr->ptr[ind];
        curr->ind = ind;
        curr->dep = fa->dep + 1;
    }
    curr->appear += 1;
}

void getFail(Trie * rt_trie){
    queue<Trie *> node_q;
    node_q.push(rt_trie);
    while(node_q.size()){
        Trie * tp_node = node_q.front();
        node_q.pop();
        for(int i = 0;i < 26;i++){
            if(tp_node->ptr[i] != nullptr){
                Trie * son_node = tp_node->ptr[i];
                if(son_node->dep == 1){
                    son_node->fail = rt_trie;
                }
                else{
                    Trie * fail_node = tp_node->fail;
                    while(fail_node != rt_trie && fail_node->ptr[i] == nullptr){
                        fail_node = fail_node->fail;
                    }
                    if(fail_node->ptr[i] != nullptr)fail_node = fail_node->ptr[i];
                    son_node->fail = fail_node;
                }
                node_q.push(son_node);
            }
        }
    }
}

ll find_ans(Trie * rt_trie, string & s){
    Trie * curr = rt_trie;
    ll ret = 0;
    for(int i = 0;i < s.size();i++){
        ll ind = s[i] - 'a';
        while(curr != rt_trie && curr->ptr[ind] == nullptr){
            curr = curr->fail;
        }
        if(curr->ptr[ind] != nullptr)curr = curr->ptr[ind];
        Trie * tp_node = curr;
        while(tp_node != rt_trie && tp_node->appear != -1){
            ret += tp_node->appear;
            tp_node->appear = -1;
            tp_node = tp_node->fail;
        }
    }
    return ret;
}

void sol(){
    cin>>n;
    Trie * rt_trie = new Trie();
    vector<string> ves(n);
    rep(i,n){
        cin>>ves[i];
        addString(rt_trie, ves[i], i);
    }
    getFail(rt_trie);

    string s;cin>>s;
    cend(find_ans(rt_trie, s));

}


int main(){
	// ios_base::sync_with_stdio(false);
	// cin.tie(nullptr);
	// cout.tie(nullptr);
		
	tt = 1;
	// cin>>tt;
	for(ttt = 1;ttt <= tt;ttt++){
		sol();
	}
	return 0;
}
