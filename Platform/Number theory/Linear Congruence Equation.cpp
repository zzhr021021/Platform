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
 
#define alice cout<<"Alice\n"
#define bob cout<<"Bob\n"
#define draw cout<<"Draw\n"
 
typedef long long ll;
const ll MOD = 998244353;
ll p = MOD;
const ll inf = 1e18;
const int N = 3e5+5;
using namespace std;
 
ll tt;
ll ttt;
ll n,k,m,x,y,d,q,f,h,w,t,R;

ll qpow(ll x,ll y)
{
    int ans=1;
    while(y)
    {
        if(y&1) ans=ans*x%p;
        x=x*x%p,y>>=1;
    }
    return ans;
}

// to solve linear congruence equation like ax = b (mod n) 
// return a triple, minans, num, diff
// make sure a > 0, n > 0, n prime

struct triple{
	ll ans, co, dif;
};

triple sollce(ll a, ll b, ll n){
	ll g = __gcd(a, n);
	if(b % g != 0)return {-1,-1,-1};
	a /= g;b /= g;n /= g;
	if(n == 1){
		return {0, g, n};
	}
	ll ans = b * qpow(a, n - 2) % n;
	return {ans, g, n};
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

	triple tp;
	tp = sollce(2,1,4);
	csp(tp.ans);csp(tp.co);csp(tp.dif);cendl;
	tp = sollce(7,2,4);
	csp(tp.ans);csp(tp.co);csp(tp.dif);cendl;
	tp = sollce(7,3,4);
	csp(tp.ans);csp(tp.co);csp(tp.dif);cendl;
	tp = sollce(7,4,4);
	csp(tp.ans);csp(tp.co);csp(tp.dif);cendl;
	
	tp = sollce(9,8,10);
	csp(tp.ans);csp(tp.co);csp(tp.dif);cendl;
	return 0;
}
