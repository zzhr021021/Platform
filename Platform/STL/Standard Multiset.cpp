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

multiset<ll, less<int>> rst;
multiset<ll, greater<int>> lst;

ll t;
ll n,k,c,m;
void sol(){
	cin>>n;
	ll cnt = 0;
	rep(i,n){
		char op;cin>>op;
		ll l, r;cin>>l>>r;
		if(op == '+'){
			cnt++;
			lst.insert(l);
			rst.insert(r);
		}
		else{
			auto it = lst.find(l);
			lst.erase(it);
			auto it2 = rst.find(r);
			rst.erase(it2);
		}
		if(cnt == 0){
			no;
		}
		else{
		
			int mx = *lst.begin(), mn = *rst.begin();
			if(mx > mn)yes;
			else no;
		}
	}
}
int main() {
	t=1;
	while(t--)sol();
	return 0;
}
