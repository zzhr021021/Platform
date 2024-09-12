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
const ll mod = 1e9+7;
const ll p = mod;
using namespace std;

ll n,m,t,k;
ll a[200005];
ll dp[200005];
void sol(){
	cin>>n;
	rep(i,n){
		cin>>a[i];
		a[i]++;
	}
	ll ans = n;
	rep(i,n+5)dp[i] = n;
	dp[n] = 0;
	for(int i = n - 1;i >= 0;i--){
		if(a[i] > n - i){
			dp[i] = 1 + dp[i + 1];
		}
		else{
			dp[i] = min(1 + dp[i + 1], dp[i + a[i]]);
		}
	}
	cend(dp[0]);
}
int main() {
	cin>>t;
	while(t--)sol();
	return 0;
}
