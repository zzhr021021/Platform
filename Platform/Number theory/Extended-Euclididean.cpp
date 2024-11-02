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
 
typedef long long int ll;
const ll MOD = 998244353;
ll p = MOD;
const ll inf = 1e18;
const int N = 3e5+5;
using namespace std;
 
ll tt;
ll ttt;
ll k,m,x,y,d,q,f,h,w,t,R;

struct triple {
    ll d, x, y;
};
triple eucl(ll a, ll b) {
    if (b == 0) {
        return {a, 1, 0};
    }
    ll k = a / b;
    triple tp = eucl(b, a - k * b);
    ll d = tp.d;
    ll x = tp.x;
    ll y = tp.y;
    return {d, y, x - k * y};
}
 
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
	// for problem like 9x + 21y = gcd(9,21) = 3
	triple tp = eucl(9, 21);
	// 3 -2 1
	// gcd x y
	csp(tp.d);csp(tp.x);csp(tp.y);cendl;
    
    // for problem like 9x = b(mod 21), find all x
    // b % gcd != 0, like b = 16, no ans
	// b % gcd == 0, like b = 15:
	ll a = 9;
	ll b = 15;
	ll n = 21;
	tp = eucl(a,n);
	ll g = tp.d;
	if(b % g != 0)cend(-1);
	else{
		a /= g;b /= g;n /= g;
		ll minans = tp.x * b % n;
		minans = (minans + n) % n;
		cend(minans);
	}
	return 0;
}
