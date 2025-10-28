#include <bits/stdc++.h>
#define debug(x) cout << #x << " = " << x << endl
#define vdebug(a)         \
	cout << #a << " = ";  \
	for (auto x : a)      \
		cout << x << " "; \
	cout << "\n";

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (ll i = 1; i <= (n); ++i)
#define rep1nr(i, n) for (int i = (n); i >= 1; --i)
#define rep01n(i, n) for (int i = 0; i <= (n); ++i)

#define ll int
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
#define rall(a) a.rbegin(), a.rend()
#define yes cout << "Yes\n"
#define no cout << "No\n"
const ll N = 200500;
using namespace std;

ll tt, ttt;
ll n, k, m, t, x, y, z, h, q, d, s;

ll a[1000500];
ll b[31][1000500];

ll tp[32];
 
void sol(){
    cin>>n>>q;
    rep1n(i,n){
        cin>>a[i];
        rep(j,31){
            b[j][i] = b[j][i - 1];
        }
        b[a[i]][i]++;
    }
    rep(iq,q){
        cin>>x>>y;
        rep(i,31){
            tp[i] = b[i][y] - b[i][x - 1];
        }
        tp[31] = 0;

        bool odd = false;
        bool flag = true;
        for(int i = 0;i <= 30;i++){
            if(odd && tp[i] % 2 == 1){
                no;
                flag = false;
                break;
            }
            tp[i + 1] += tp[i] >> 1;
            tp[i] &= 1;
            if(tp[i]){
                odd = true;
            }
        }
        if(flag == false){
            continue;
        }
        if(odd && tp[31] != 0){
            no;
        }
        else if(tp[31] != 0 && __builtin_popcount(tp[31]) != 1){
            no;
        }
        else{
            yes;
        }
    }

}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	tt = 1;
	// cin >> tt;
	for (ttt = 1; ttt <= tt; ttt++)
	{
		sol();
	}
	system("pause");
	return 0;
}