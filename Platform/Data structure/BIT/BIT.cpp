#include<bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define rep1(i, n) for (ll i = 1; i < (n); ++i)
#define rep1n(i, n) for (ll i = 1; i <= (n); ++i)
#define rep01n(i, n) for (ll i = 0; i <= (n); ++i)
#define repr(i, n) for (ll i = (n) - 1; i >= 0; --i)
#define csp(n) cout << n << " ";
#define cend(n) cout << n << endl;
#define cendl cout << endl;

#define ll long long

#define vll vector<ll>

const ll MOD = 1e9+7;
const ll p = MOD;
using namespace std;

ll n,m,t,k;

// maintain n listed elements
// can add a value to a element in logn
// can query the summation of a segment in logn
struct BIT_sum{
    int n;
    vll fenw;
    // initialize 
    void init(ll pa_n){
        n = pa_n;
        fenw.resize(pa_n);
        for(auto & o : fenw){
            o = 0;
        }
    }
    void init(vll & pa_ve){
        n = pa_ve.size();
        fenw.resize(n);
        rep(i,n){
            add(i, pa_ve[i]);
        }
    }
    void add(ll pos, ll val){
        while (pos < fenw.size()){
            fenw[pos] += val;
            fenw[pos] = (fenw[pos] % MOD + MOD) % MOD;
            pos |= (pos + 1);
        }
    }
    ll get(ll pos){
        ll res = 0;
        while (pos >= 0){
            res += fenw[pos];
            res %= MOD;
            pos &= (pos + 1);
            pos--;
        }
        return res;
    }
    ll get(ll l, ll r){
        ll vr = get(r);
        ll vl = get(l - 1);
        return ((vr - vl) % MOD + MOD) % MOD;
    }
};

int main(){
    BIT_sum t_bit;
    
	return 0;
}
