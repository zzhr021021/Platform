//Codeforces Round 909 (Div. 3) G

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

typedef long long ll;
const ll mod = 1e9+7;
const ll p = mod;
using namespace std;

ll tt;
ll n,k,c,m,q,x;


void sol(){
	cin>>n>>k;
	ll ans = n * k;
	ll l = 1, r = 1;
	for(;l <= n;l = r + 1){
		if(k / l != 0)r = min(k / (k / l), n);
		else r = n;
		ans -= (k / l) * (r - l + 1) * (l + r) / 2; 
	}
	cend(ans);
}
int main() {
	tt = 1; 
	while(tt--)sol();
	return 0;
}