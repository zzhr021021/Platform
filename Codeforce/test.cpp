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

ll tt, ttt;
ll n,k,m,t,x,y,z,h,q,r;

ll sqa_dis(ll x, ll y){
	return x * x + y * y;
}
struct stone{
	ll d,m,p,r;
}stones[250050];
bool cmp(const stone & u, const stone & v){
	return u.d < v.d;
}
ll segmn[1000050];
queue<stone> llist[250005];

void sol(){
	// input 
	cin>>x>>y>>p>>r>>n;
	set<ll> stx, sty;
	map<ll, ll> ijx, ijy;
	stx.insert(0);sty.insert(0);
	stx.insert(r);sty.insert(p);
	ll cx = 0, cy = 0;
	rep(i,n){
		ll xx,yy;
		cin>>xx>>yy>>stones[i].m>>stones[i].p>>stones[i].r;
		stones[i].d = ceil(sqrt(sqa_dis(xx - x, yy - y)));
		stx.insert(stones[i].d);
		stx.insert(stones[i].r);
		sty.insert(stones[i].m);
		sty.insert(stones[i].p);
	}
	// sort
	sort(stones, stones + n, cmp);
	// discretization 
	for(auto o : stx){ijx[o] = cx;cx++;}
	for(auto o : sty){ijy[o] = cy;cy++;}
	rep(i,n){
		stones[i].d = ijx[stones[i].d];
		stones[i].r = ijx[stones[i].r];
		stones[i].m = ijy[stones[i].m];
		stones[i].p = ijy[stones[i].p];
	}
	// set linklist
	rep(i,n){
		llist[stones[i].m].push(stones[i]);
	}
	rep(i,250005)llist[i].push({inf, inf, inf, inf});
	// bfs-like
	ll ans = 0;
	queue<stone> q;
	q.push({r, p, 0, 0});
	while(q.size()){
		break;;
	}
	cend(ans);
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