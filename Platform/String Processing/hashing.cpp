#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)
#define rep1nr(i, n) for (int i = (n); i >= 1; --i)
#define rep01n(i, n) for (int i = 0; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define csp(n) cout << n << " "
#define cend(n) cout << n << endl
#define cendl cout << endl
#define ctest cout << "test   "
#define pb push_back
 
#define alice cout<<"Alice\n"
#define bob cout<<"Bob\n"
#define draw cout<<"Draw\n"
 
typedef long long int ll;
const ll MOD = 1e9+7;
const ll MODD = 1e9+9;
ll p = MOD;
const ll inf = 1e18;
const int N = 3e5+5;
using namespace std;
 
ll tt;
ll ttt;
ll n,k,m,d,q,f,h,w,t,x,y;

void printvec(vector<int> & v){
	for(auto &x : v){
		cout << x << " ";
	}
	cendl;
}

ll a[N];
ll b = 37363531;
ll bp[N];
ll bpp[N];
ll pre[N];
ll pree[N];

void sol(){
	cin>>n;
	string s;cin>>s;
	pre[0] = pree[0] = s[0];
	for(int i = 1;i < n;i++){
		pre[i] = (pre[i - 1] * b) % MOD;
		pre[i] = (pre[i] + s[i]) % MOD;
		pree[i] = (pree[i - 1] * b) % MODD;
		pree[i] = (pree[i] + s[i]) % MODD;
	}
	set<pair<ll, ll>> st;
	for(int i = 2;i <= n;i++){
		pair<ll, ll> tp;
		
		ll tail, head;
		
		if(i == n)tail = 0;
		else tail = (pre[n - 1] - pre[i - 1] * bp[n - i] % MOD + MOD) % MOD;
		if(i == 2)head = 0;
		else head = pre[i - 3];
		
		tp.first = (tail + head * bp[n - i] % MOD) % MOD;
		
		
		if(i == n)tail = 0;
		else tail = (pree[n - 1] - pree[i - 1] * bpp[n - i] % MODD + MODD) % MODD;
		if(i == 2)head = 0;
		else head = pree[i - 3];
		
		tp.second = (tail + head * bpp[n - i] % MODD) % MODD;
//		ctest;csp(tp.first);cend(tp.second);
		st.insert(tp);
	}
	
	
	cend(st.size());
}

 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	bp[0] = bpp[0] = 1;
	rep1n(i,2e5){
		bp[i] = (bp[i - 1] * b) % MOD;
		bpp[i] = (bpp[i - 1] * b) % MODD;
	}
	
    cin>>tt;
	for(ttt = 1;ttt <= tt;ttt++){
		sol();
	}
	return 0;
}
