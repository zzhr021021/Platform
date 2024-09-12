#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)
#define rep1nr(i, n) for (int i = (n); i >= 1; --i)
#define rep01n(i, n) for (int i = 0; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)

#define pll pair<ll, ll>
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
 
typedef long long int ll;
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

struct Point{
	ll x;
	ll y;
	ll index;
};

bool ascPointx(Point p1, Point p2){
	return p1.x < p2.x;
}

bool ascy(pll x, pll y){
	return x.second < y.second;
}

ll distsq(ll x1, ll y1, ll x2, ll y2){
	ll dx = llabs(x2 - x1);
	ll dy = llabs(y2 - y1); 
	return dx * dx + dy * dy;
}

vector<Point> mergevec(vector<Point> & ve1, vector<Point> & ve2){
	ll n1 = ve1.size();
	ll n2 = ve2.size();
	ll po1 = 0, po2 = 0;
	
	vector<Point> ret;
	while(po1 != n1 || po2 != n2){
		if(po1 != n1 && po2 != n2){
			if(ve1[po1].y < ve2[po2].y){
				ret.pb(ve1[po1]);
				po1++;
			}
			else{
				ret.pb(ve2[po2]);
				po2++;
			}
		}
		else if(po1 == n1 && po2 != n2){
			ret.pb(ve2[po2]);
			po2++;
		}
		else if(po1 != n1 && po2 == n2){
			ret.pb(ve1[po1]);
			po1++;
		}
	}
	return ret;
}

struct helpstruct{
	double db;
	ll sq;
	ll index1;
	ll index2;
	vector<Point> partarray;
};

// get the nearest point pair in a 2D-space.
// extend the code to get the indices of the 2 points.
helpstruct partsolve(vector<Point> & ps, ll l, ll r){
	if(l == r){
		vector<Point> ret;
		ret.pb(ps[l]);
		return {(double)1e9, (ll)1e18, -1, -1, ret};
	}
	if(r - l == 1){
		ll dsq = distsq(ps[l].x, ps[l].y, ps[r].x, ps[r].y);
		vector<Point> r1, r2;
		r1.pb(ps[l]);
		r2.pb(ps[r]);
		vector<Point> ret = mergevec(r1, r2);
		return {sqrt(dsq), dsq, l, r, ret};
	}
	
	ll mid = (l + r) / 2;
	auto ansl = partsolve(ps, l, mid);
	auto ansr = partsolve(ps, mid + 1, r);
	double recdb;
	ll recsq, recl, recr;
	helpstruct * ansptr;
	if(ansl.db < ansr.db)ansptr = & ansl;
	else ansptr = & ansr;
	recdb = ansptr->db;
	recsq = ansptr->sq;
	recl = ansptr->index1;
	recr = ansptr->index2;
	
	vector<Point> psall = mergevec(ansl.partarray, ansr.partarray);
	vector<Point> ips;
	for(auto o : psall){
		if((double)o.x > (double)ps[mid].x - recdb && (double)o.x < (double)ps[mid].x + recdb){
			ips.pb(o);
		}
	}
	ll iup = 0;
	for(int i = 0;i < ips.size();i++){
		while(iup < ips.size() - 1 && (double)ips[iup + 1].y - (double)ips[i].y < recdb){
			iup++;
		}
		for(int j = i + 1;j <= iup;j++){
			ll testsq = distsq(ips[j].x, ips[j].y, ips[i].x, ips[i].y);
			if(testsq < recsq){
				recsq = testsq;
				recdb = sqrt(testsq);
				recl = ips[i].index;
				recr = ips[j].index;
			}
		}
	}
	
	return {recdb, recsq, recl, recr, psall};
	
}

void sol(){
	cin>>n;
	vector<Point> ps;
	rep(i,n){
		cin>>x>>y;
		ps.pb({x, y, i});
	}
	sort(ps.begin(), ps.end(), ascPointx);
	
	auto ans = partsolve(ps, 0, n - 1);
	auto anssq = ans.sq;
	cout << anssq;
//	cout << setprecision(4) << fixed << sqrt(anssq);
	
	
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
//	initinv();
		
	tt = 1;
//	cin>>tt;
	for(ttt = 1;ttt <= tt;ttt++){
		sol();
	}
	return 0;
}
