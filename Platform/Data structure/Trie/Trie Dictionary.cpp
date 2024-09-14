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

struct Trie{
    ll val = 0;
    Trie * ptr[26];
    bool endNode;
    Trie(){
        val = 0;
        endNode = false;
        rep(i,26){
            ptr[i] = nullptr;
        }
    }

};

void addString(Trie * p_trie, string & s){
    Trie * curr = p_trie;
    ll sn = s.size();
    rep(i,sn){
        ll ind = s[i] - 'a';
        if(curr->ptr[ind] == nullptr){
            Trie * node = new Trie();
            curr->ptr[ind] = node;
        }
        curr = curr->ptr[ind];
    }
    curr->endNode = true;
    curr->val += 1;
}

ll queryPrefix(Trie * p_trie, string & s){
    Trie * curr = p_trie;
    ll sn = s.size();
    ll ret = 0;
    rep(i,sn){
        ll ind = s[i] - 'a';
        if(curr->ptr[ind] != nullptr){
            curr = curr->ptr[ind];
            if(curr->endNode == true)ret += curr->val;
        }
        else{
            return ret;
        }
    }
    return ret;
}


void sol(){
    cin>>n>>m;
    Trie * rt_trie = new Trie();
    ll ans = 0;
    string s;
    rep(i,n){
        cin>>s;
        addString(rt_trie, s);
    }
    rep(i,m){
        cin>>s;
        cend(queryPrefix(rt_trie, s));
    }

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
    system("pause");
	return 0;
}