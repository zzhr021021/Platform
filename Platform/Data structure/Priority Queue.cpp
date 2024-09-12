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

// smaller will come out first
priority_queue<ll, vector<ll>, greater<ll>> post;

// bigger will come out first
priority_queue<ll> post;
int main() {
	// should empty it this way
	post = priority_queue<ll, vector<ll>, greater<ll>>();
	
	return 0;
}
