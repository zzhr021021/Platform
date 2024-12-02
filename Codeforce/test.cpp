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
const ll N = 1e6;
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

ll fenw[200050];
vpl seq;

void recover(){
	while(seq.size()){
		auto o = seq.back();seq.pop_back();
		fenw[o.first] = o.second;
	}
}
inline ll pa(ll x){
	ll tp = x & (-x);
	return x - tp;
}
void add(ll pos, ll val){
    while (pos < 200050){
    	seq.push_back(pos, fenw[pos]);
        fenw[pos] += val; 
        pos |= (pos + 1);
    }
}
void change(ll pos, ll val){
	
}
ll get(ll pos){
    ll res = 0;
    while (pos >= 0){
        res += fenw[pos];
        pos &= (pos + 1);
        pos--;
    }
    return res;
}
ll get(ll l, ll r){
    ll vr = get(r);
    ll vl = get(l - 1);
    return vr - vl;
}

struct qu{
	ll type, l, r, val, id;
}qus[200050], qu1[200050], qu2[200050];
ll cntq, cnt1, cnt2;

ll ans[200050];

void sol(){
	cin>>n>>m;
	rep(i,n){
		cin>>x;
		
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
