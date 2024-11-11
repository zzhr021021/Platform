#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < n;i++)
#define ll long long
#define cend(x) cout << x << endl
#define csp(x) cout << x << " "
#define ctest cout << "test  "
using namespace std;

ll qpow(ll x, ll y, ll p){
	if(y == 0)return 1;
	ll ret = 1;
	if(y & 1)ret = x;
	ll tp = qpow(x, y / 2, p);
	ret *= tp * tp % p;
	ret %= p;
	return ret;
}

// given a, b, p, gcd(a, p) == 1, answer the minimum x that a^x == b (mod p)
// make sure gcd(a, p) == 1
// decomposote x to i * t - j, t = sqrt(p)
// output -1 if no such x exists
ll baby_step_giant_step(ll a, ll b, ll p){
	ll t = sqrt(p);
	map<ll, ll> right;
	set<ll> st;
	rep(i,t){
		ll tp = b * qpow(a, i, p) % p;
		right[tp] = i;
		st.insert(tp);
	}
	ll at = qpow(a, t, p);
	rep(i,t + 3){
		ll tp = qpow(at, i, p);
		if(st.count(tp)){
			ll j = right[tp];
			return i * t - j;
		}
	}
	return -1;
}

ll t,k;
ll y,z,p;

void solve(){
	cin>>t;
	rep(iq,t){
		cin>>y>>z>>p;
        y %= p;
        z %= p;
        if(y == 0 && z == 0){
            cend(1);
        }
        else if(y == 0 || z == 0){
            cend("Orz, I cannot find x!");
        }
        else if(p == 2){
            if(y % 2 == z % 2){
                cend(1);
            }
            else{
                cend("Orz, I cannot find x!");
            }
        }
        else{
            ll ans = baby_step_giant_step(y, z, p);
            if(ans == -1)cend("Orz, I cannot find x!");
            else cend(ans);
        }
	}
}

int main(int argc, char const *argv[])
{
	solve();
	system("pause");
	return 0;
}

