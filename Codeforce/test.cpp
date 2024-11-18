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
ll n,k,m,t,x,y,z,h,q;

ll a[10000];
ll seg[40050];
ll b[10050];
void init(){

}
void maintain(ll o){
	seg[o] = seg[o << 1] + seg[o << 1 | 1];
}
void add(ll o, ll l, ll r, ll L, ll R, ll val){
}
void add(ll o, ll l, ll r, ll pos, ll val){
	if(pos < l || pos > r)return;
	if(l == r){
		seg[o] += val;
		return;
	}
	else{
		ll mid = (l + r) / 2;
		add(o << 1, l, mid, pos, val);
		add(o << 1 | 1, mid + 1, r, pos, val);
		maintain(o);
	} 
}
ll query(ll o, ll l, ll r, ll L, ll R){
	if(r < L || l > R)return 0;
	if(l >= L && r <= R)return seg[o];
	ll ret = 0;
	ll mid = (l + r) / 2;
	ret += query(o << 1, l, mid, L, R);
	ret += query(o << 1 | 1, mid + 1, r, L, R);
	return ret;
}

void sol(){
	// input 
	cin>>n;
	for(int i = 1;i < n;i++){
		cin>>a[i];
	}

	rep1n(i,n){
		add(1, 0, n, i, 1);
	}
	repr(i,n){
		ll l = 0, r = n;
		while(l != r){
			ll mid = (l + r) / 2;
			if(query(1, 0, n, 0, mid) <= a[i]){
				l = mid + 1;
			}
			else{
				r = mid;
			}
		}
		add(1, 0, n, l, -1);
		b[i] = l;
	}
	rep(i,n){
		cend(b[i]);
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
