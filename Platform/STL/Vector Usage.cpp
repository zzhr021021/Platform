#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)
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
const ll MOD = 998244353;
ll p = MOD;
const ll inf = 1e18;
const int N = 3e5+5;
using namespace std;
 
ll tt;
ll ttt;
ll n,k,m,x,y,d,q,f,h,w,t,R;
ll a[N];

vector<ll> g[N];

void cvec(vector<ll> & v){
	for(auto o : v){
		csp(o);
	}
	cendl;
}

bool samev(vector<ll> & v1, vector<ll> & v2){
	if(v1.size() != v2.size())return false;
	else{
		ll n = v1.size();
		rep(i,n){
			if(v1[i] != v2[i])return false;
		}
		return true;
	}
}

void sol(){
	cin>>n>>k;
	 
}
 
int main(){
//	ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);

    
    cin>>tt;
	for(ttt = 1;ttt <= tt;ttt++){
		sol();
	}
	return 0;
}
