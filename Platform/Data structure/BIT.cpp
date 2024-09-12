#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)
#define rep01n(i, n) for (int i = 0; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)
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
ll a[15] = {0,1,2,3,4,5,6,7,8,9,10,32,11,33,11};//use 14 elements

ll pa(ll x){
	ll tp = x & (-x);
	return x - tp;
}
void add(int pos, long long val, vector<long long>& fenw)
{
    while (pos < fenw.size())
    {
        fenw[pos] += val;
        fenw[pos] = (fenw[pos] % MOD + MOD) % MOD;
        pos |= (pos + 1);
    }
}
 
long long get(int pos, vector<long long>& fenw)
{
    long long res = 0;
    while (pos >= 0)
    {
        res += fenw[pos];
        res %= MOD;
        pos &= (pos + 1);
        pos--;
    }
    return res;
}
 
long long get(int l, int r, vector<long long>& fenw)
{
    long long vr = get(r, fenw);
    long long vl = get(l - 1, fenw);
    return ((vr - vl) % MOD + MOD) % MOD;
}

int main() {
	vector<ll> fenw1(14);
	rep(i,14)add(i, a[i], fenw1);
	cend(get(0, 4, fenw1));
	cend(get(5, 9, fenw1));
	return 0;
}
