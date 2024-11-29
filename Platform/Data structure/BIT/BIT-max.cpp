#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)

#define ll long long
#define ull unsigned long long
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define vb vector<bool>

#define csp(n) cout << n << " "
#define cend(n) cout << n << endl
#define cendl cout << endl
#define ctest cout << "test   "
#define all(a) a.begin(), a.end()
const ll inf = 1e18;
const ll N = 1e6;
using namespace std;

ll tt, ttt;
ll n,m,x,y;

// BIT
vll fenw(1000050, -inf);
ll pa(ll x){
	ll tp = x & (-x);
	return x - tp;
}
void modify(int pos, long long val){
    while (pos < fenw.size()){
        fenw[pos] = max(fenw[pos], val);
        pos |= (pos + 1);
    }
}
ll query(int pos){
    ll res = -inf;
    while (pos >= 0){
        res = max(res, fenw[pos]);
        pos &= (pos + 1);
        pos--;
    }
    return res;
}

void sol(){
    
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
