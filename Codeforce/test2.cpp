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

const ll MOD = 1e9 + 7;
const ll MODD = 1e9 + 9;
ll p = MOD;
const ll inf = 1e18;
const ll INF = 1e18; 
using namespace std;
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

ll tt, ttt;
ll n,k,m,t,x,y,z,h,q;

const int N = 100010;
struct Treap{
	ll l, r;
	ll val, dat;
	ll cnt, size;
} a[N];
ll tot = 0;
ll root = 1;
ll newnode(ll x){
	tot++;
	a[tot].val = x;
	a[tot].dat = rnd();
	a[tot].cnt = a[tot].size = 1;
	return tot;
}
ll update(ll o){
	a[o].size = a[a[o].l].size + a[a[o].r].size + a[o].cnt;
}
void build(){
	newnode(-inf);
	newnode(inf);
	a[1].r = 2;
	root = 1;
	update(root);
}
// size of nullptr is 0
ll getrankbyval(ll o, ll x){
	if(o == 0)return 0;
	if(a[o].val > x)return getrankbyval(a[o].l, x);
	else if(a[o].val == x)return a[a[o].l].size;
	else return a[a[o].l].size + getrankbyval(a[o].r, x) + a[o].cnt;
}
ll getvalbyrank(ll o, ll x){
	if(a[a[o].l].size >= x)return getvalbyrank(a[o].l, x);
	else if(a[a[o].l].size + a[o].cnt >= x)return a[o].val;
	else return getvalbyrank(a[o].r, x - (a[a[o].l].size + a[o].cnt));
}
void zig(ll & o){
	ll u = a[o].l;
	a[o].l = a[u].r;
	a[u].r = o;
	o = u;
	update(a[o].r);update(o);
}
void zag(ll & o){
	ll u = a[o].r;
	a[o].r = a[u].l;
	a[u].l = o;
	o = u;
	update(a[o].l);update(o);
}
void insert(ll & o, ll x){
	if(p == 0){
		p = newnode(x);
		return;	
	}
	if(x == a[o].val){
		a[o].cnt++;
		update(p);
		return;
	}
	if(x < a[o].val){
		insert(a[o].l, x);
		if(a[a[o].l].dat > a[o].dat)zig(o);
	}
	else{
		insert(a[o].r, x);
		if(a[a[o].r].dat > a[o].dat)zag(o);
	}
	update(o);
}
ll getpre(ll x){
	ll rank = getrankbyval(1, x);
	return getvalbyrank(1, rank - 1);
}
ll getsuf(ll x){
	
}
void remove(ll & o, ll x){
	if(o == 0)return;
	if(x == a[o].val){
		a[o].cnt--;
	}
	update(o);
}

// you need to maintain a data structure M dynamicly, which providing 6 diffenrent kinds of operations:
// M is a multiple set
// 1. insert a number x in M
// 2. delete a copy of x in M
// 3. query: the rank of x (rank of x is the number of numbers less than x, plus 1) 
// 4. if sort M, M[x]
// 5. pre of x
// 6. suf of x 
// so this is treap
void sol(){
	// input 
	cin>>n;
	build();
	rep(iop,n){
		ll op;cin>>op>>x;
		if(op == 1){
			
		}
		else if(op == 2){
			
		}
		else if(op == 3){
			
		}
		else if(op == 4){
			
		}
		else if(op == 5){
			
		}
		else{
			
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
