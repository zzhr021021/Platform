#include<bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define rep1(i, n) for (ll i = 1; i < (n); ++i)
#define rep1n(i, n) for (ll i = 1; i <= (n); ++i)
#define rep01n(i, n) for (ll i = 0; i <= (n); ++i)
#define repr(i, n) for (ll i = (n) - 1; i >= 0; --i)
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define csp(n) cout << n << " ";
#define cend(n) cout << n << endl;
#define cendl cout << endl;

typedef long long ll;
const ll MOD = 1e9+7;
const ll p = MOD;
using namespace std;

ll n,m,t,k;
//use 14 elements
ll a[15] = {0,1,2,3,4,5,6,7,8,9,10,32,11,33,11};

ll pa(ll x){
	ll tp = x & (-x);
	return x - tp;
}
void add(ll pos, ll val, vector<ll>& fenw){
    while (pos < fenw.size()){
        fenw[pos] += val;
        fenw[pos] = (fenw[pos] % MOD + MOD) % MOD;
        pos |= (pos + 1);
    }
}
 
ll get(ll pos, vector<ll>& fenw){
    ll res = 0;
    while (pos >= 0){
        res += fenw[pos];
        res %= MOD;
        pos &= (pos + 1);
        pos--;
    }
    return res;
}
 
ll get(ll l, ll r, vector<ll>& fenw){
    ll vr = get(r, fenw);
    ll vl = get(l - 1, fenw);
    return ((vr - vl) % MOD + MOD) % MOD;
}

int main(){
	vector<ll> fenw1(14);
	rep(i,14)add(i, a[i], fenw1);
	cend(get(0, 4, fenw1));
	cend(get(5, 9, fenw1));
	return 0;
}
