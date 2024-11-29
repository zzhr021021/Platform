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
#define vstr vector<string>
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


const ll MOD = 1e9 + 7;
const ll MODD = 1e9 + 9;
const ll MOOD = 666623333;
ll p = MOD;
const ll inf = 1e18;
const ll INF = 1e18; 
// ll dix[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
// ll diy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
using namespace std;
// mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

void printvec(vll & v){
    for(auto o : v){
        csp(o);
    }
    cendl;
}

ll tt, ttt;
ll n,k,m,t,x,y,z,h,r;
ll a[300050];
struct node{
    ll l, r, isend, le;
}trie[30 * 300050];
vll roots;
ll tot = 0;
ll cur = 0;
// let logU = 25
void insert(ll x, ll k, ll p, ll q){
    tot++;
    if(k == -1){
        trie[p].isend = true;
        trie[p].le = cur;
        return;
    }
    if(k == 24){
        roots.push_back(p);
    }
    trie[p].l = trie[q].l;
    trie[p].r = trie[q].r;
    
    if((x >> k) & 1){
        trie[p].r = p + 1;
        insert(x, k - 1, p + 1, trie[q].r);
    }
    else{
        trie[p].l = p + 1;
        insert(x, k - 1, p + 1, trie[q].l);
    }
    trie[p].le = cur;
    if(trie[p].l != 0){
        trie[p].le = min(trie[p].le, trie[trie[p].l].le);
    }
    if(trie[p].r != 0){
        trie[p].le = min(trie[p].le, trie[trie[p].r].le);
    }
}
ll ask(ll l, ll r, ll x){
    ll p = roots[r];
    ll ret = x;
    for(int i = 24;i >= 0;i--){
        if(trie[p].le >= l && (trie[p].r == 0 || ((x >> i) & 1) == 1)){
            p = trie[p].l;
        }
        else{
            ret ^= (1 << i);
            p = trie[p].r;
        }
    }
    return ret;
}
ll allxor = 0;

void sol(){
    cin>>n>>m;
    rep(i,n){
        cin>>a[i];
        allxor ^= a[i];
    }
    cur = 0;
    insert(0, 24, tot + 1, roots.back());
    rep(i,n){
        cur = i + 1;
        insert(a[i], 24, tot + 1, roots.back());
    }
    rep(i,m){
        char op;cin>>op;
        if(op == 'A'){
            cin>>x;
            cur++;
            insert(x, 24, tot + 1, roots.back());
        }
        else{
            ll l, r;cin>>l>>r>>x;
            ll thexor = allxor ^ x;
            cend(ask(l - 1, r - 1, x));
        }
    }
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    tt = 1;
    // cin>>tt;
    for(ttt = 1;ttt <= tt;ttt++){
        sol();
    }
    system("pause");
    return 0;
}