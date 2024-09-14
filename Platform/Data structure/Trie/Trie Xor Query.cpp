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

struct Trie
{
    ll val = 0;
    Trie * ptr[2];
    bool endNode;
    Trie(){
        endNode = false;
        rep(i,2){
            ptr[i] = nullptr;
        }
    }

};

void addNum(Trie * p_trie, ll x){
    Trie * curr = p_trie;
    vll bs(32);
    for(int i = 31;i >= 0;i--){
        bs[31 - i] = (x >> i) & 1;
    }
    for(int i = 0;i < 32;i++){
        if(curr->ptr[bs[i]] == nullptr){
            Trie * node = new Trie();
            curr->ptr[bs[i]] = node;
        }
        curr = curr->ptr[bs[i]];
    }
    curr->endNode = true;
}

ll queryMax(Trie * p_trie, ll x){
    Trie * curr = p_trie;
    ll ans = 0;
    vll bs(32);
    for(int i = 31;i >= 0;i--){
        bs[31 - i] = (x >> i) & 1;
    }
    for(int i = 0;i < 32;i++){
        if(curr->ptr[1 - bs[i]] != nullptr){
            ans += (ll)1 << (31 - i);
            curr = curr->ptr[1 - bs[i]];
        }
        else{
            curr = curr->ptr[bs[i]];
        }
    }
    return ans;
}


void sol(){
    cin>>n;
    Trie * rt_trie = new Trie();
    ll ans = 0;
    rep(i,n){
        cin>>x;
        if(i > 0){
            ans = max(ans, queryMax(rt_trie, x));
        }
        addNum(rt_trie, x);
    }
    cend(ans);

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