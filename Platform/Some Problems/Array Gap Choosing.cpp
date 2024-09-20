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

// 

struct Point
{
    ll val;
    ll l, r;
};

void delpoint(vector<Point> & v, ll pos){
    if(v[pos].l != -1){
        v[v[pos].l].r = v[pos].r;
    } 
    if(v[pos].r != -1){
        v[v[pos].r].l = v[pos].l;
    } 

}

// given an positive array 
// give a resonable number m, choose m number from array
// make their sum mininum, but any two chosen elements can not be adjacent.
void sol(){
    k = 2;
    vector<Point> vd;
    vb banned;
    rep(i,n+5){
        vd.pb({inf, vd.size() - 1, vd.size() + 1});
    }
    vd.pb({2, vd.size() - 1, vd.size() + 1});
    vd.pb({1, vd.size() - 1, vd.size() + 1});
    vd.pb({2, vd.size() - 1, vd.size() + 1});
    vd.pb({2, vd.size() - 1, vd.size() + 1});

    rep(i,n+5){
        vd.pb({inf, vd.size() - 1, vd.size() + 1});
    }
    vd[vd.size() - 1].r = -1;

    priority_queue<pll, vector<pll>, greater<pll>> pq;
    for(int i = 0;i < vd.size();i++){
        pq.push({vd[i].val, i});
        banned.pb(false);
    }
    
    ll ans = 0;
    rep(ik,k){
        while(banned[pq.top().second])pq.pop();
        auto o = pq.top();
        ans += o.first;
        banned[o.second] = true;
        banned[vd[o.second].l] = true;
        banned[vd[o.second].r] = true;
        ll tpval = vd[vd[o.second].l].val + vd[vd[o.second].r].val - o.first;
        ll pos = vd.size();
        delpoint(vd, vd[o.second].l);
        delpoint(vd, vd[o.second].r);
        vd.pb({tpval, vd[o.second].l, vd[o.second].r});
        vd[vd[o.second].l].r = pos;
        vd[vd[o.second].r].l = pos;
        banned.pb(false);
        pq.push({tpval, pos});
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