#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)

#define ll long long
#define ull unsigned long long
#define pll pair<long long, long long>
#define vi vector<int>

#define csp(n) cout << n << " "
#define cend(n) cout << n << endl
#define cendl cout << endl
#define ctest cout << "test   "
#define pb push_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

const ll MOD = 1e9;
ll p = MOD;
const ll inf = 1e18;
const ll INF = 1e18; 
const int N = 200005;
using namespace std;

ll tt, ttt;
ll n,k,m,d,t,x,y,z,h,q;
const int base = 1000000000;
const int base_digits = 9;

ll a[100005];
ll b[100005];

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

void sol(){
	cin>>n;
	ll xk = 0;
	ll mk = 1;
	ll thelcm = 1;
	rep(i,n){
		cin>>a[i]>>b[i];
		auto tp = eucl(mk, a[i]);
		ll am = (b[i] - xk) / tp.d * tp.x;
		ll ax = xk + mk * am;
		thelcm = thelcm * a[i] / eucl(thelcm, a[i]).d;
		mk = thelcm;
		xk = (ax % mk + mk) % mk;
	}
	cend(xk);

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