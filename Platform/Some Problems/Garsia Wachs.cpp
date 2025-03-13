#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (ll i = 1; i <= (n); ++i)
#define rep1nr(i, n) for (int i = (n); i >= 1; --i)
#define rep01n(i, n) for (int i = 0; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define replr(i, l, r) for (int i = l;i <= r;i++)

#define ll long long
#define ull unsigned long long
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define vb vector<bool>
#define vpl vector<pair<long long, long long>>

#define csp(n) cout << n << " "
#define cend(n) cout << n << endl
#define cendl cout << endl
#define ctest cout << "test   "
#define cgap cout << "--------------------" << endl
#define pb push_back
#define all(a) a.begin(), a.end()

const ll MOD = 1e9 + 7;
ll p = MOD;
const ll inf = 1e18;
const ll INF = 1e18;
const ll N = 200500;
using namespace std;

ll tt, ttt;
ll n,k,m,t,x,y,z,h,s;
// garsia wachs, Luogu P5569
// using linked table, with O(n*max(ai)) complexity

ll l[200500];
ll r[200500];
ll a[200500];
void sol(){
    cin>>n;
    a[0] = a[n + 1] = inf;
    rep1n(i,n){
        cin>>a[i];
    }
    ll ans = 0;
    for(int i = 0;i <= n;i++){
        l[i + 1] = i;
        r[i] = i + 1;        
    }
    while(n != 1){
        n--;
        ll pos = r[0];
        while(a[l[pos]] > a[r[pos]]){
            pos = r[pos];
        }
        a[pos] += a[l[pos]];
        ans += a[pos];
        ll lpos = l[pos];
        l[pos] = l[l[pos]];
        r[l[pos]] = pos;

        if(a[l[pos]] >= a[pos]){
            continue;
        }
        ll hpos = l[pos];
        while(a[hpos] < a[pos]){
            hpos = l[hpos];
        }        
        ll pos1 = r[hpos];
        ll pos2 = l[pos];
        ll pos3 = r[pos];
        r[hpos] = pos;
        l[pos1] = pos;
        r[pos2] = pos3;
        l[pos3] = pos2;
        l[pos] = hpos;
        r[pos] = pos1;

    }

    cend(ans);
}

int main(){
	// ios_base::sync_with_stdio(false);
	// cin.tie(nullptr);
	// cout.tie(nullptr);
	
	tt = 1;
	// cin>>tt;
	for(ttt = 1;ttt <= tt;ttt++){
		sol();
	}
	system("pause");
	return 0;
}