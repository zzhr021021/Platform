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
// 1-indexed: maintain n listed elements in [1, n]
// supports point update and prefix/segment (product or xor) query in logn, space is n + 1
class BIT_sum{
private:
    int n;
    vll fenw;

public:
    ll size(){
        return n;
    }
    void init(ll pa_n){
        n = pa_n;
        fenw.assign(n + 1, 0);
    }
    void init(const vll & pa_ve){
        n = pa_ve.size();
        fenw.assign(n + 1, 0);
        rep(i,n){
            fenw[i + 1] = (pa_ve[i] % MOD + MOD) % MOD;
        }
        rep1n(i,n){
            ll nxt = i + (i & -i);
            if(nxt <= n){
                fenw[nxt] += fenw[i];
                fenw[nxt] %= MOD;
            }
        }
    }
    void init(ll a[], ll st, ll pa_n){
        n = pa_n;
        fenw.assign(n + 1, 0);
        rep(i,n){
            fenw[i + 1] = (a[st + i] % MOD + MOD) % MOD;
        }
        rep1n(i,n){
            ll nxt = i + (i & -i);
            if(nxt <= n){
                fenw[nxt] += fenw[i];
                fenw[nxt] %= MOD;
            }
        }
    }
    void add(ll pos, ll val){
        while (pos <= n){
            fenw[pos] += val;
            fenw[pos] = (fenw[pos] % MOD + MOD) % MOD;
            pos += pos & -pos;
        }
    }
    ll get(ll pos){
        ll res = 0;
        while (pos > 0){
            res += fenw[pos];
            res %= MOD;
            pos -= pos & -pos;
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
