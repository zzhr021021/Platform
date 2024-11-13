#include<bits/stdc++.h>
#define rep(i,n)for(int i = 0;i < n;i++)
#define ctest cout << "test   "
#define cend(x) cout << x << endl;
#define csp(x) cout << x << " ";
#define ll long long 
#define vll vector<long long>

using namespace std;

ll x1[105];
ll x2[105];
ll yy1[105];
ll y2[105];

ll n,a,b;

int main(int argc, char const *argv[])
{
    cin>>n>>a>>b;
    ll ans = 0;
    rep(i,n){
        cin>>x1[i]>>yy1[i]>>x2[i]>>y2[i];
        vll x, y;
        x.push_back(0);
        x.push_back(a);
        x.push_back(x1[i]);
        x.push_back(x2[i]);
        y.push_back(0);
        y.push_back(b);
        y.push_back(yy1[i]);
        y.push_back(y2[i]);
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        rep(ii,x.size() - 1){
            rep(jj,y.size() - 1){
                if(x[ii] >= 0 && x[ii + 1] <= a){
                    if(y[jj] >= 0 && y[jj + 1] <= b){
                        if(x[ii] >= x1[i] && x[ii + 1] <= x2[i]){
                            if(y[jj] >= yy1[i] && y[jj + 1] <= y2[i]){
                                ans += (x[ii + 1] - x[ii]) * (y[jj + 1] - y[jj]);
                            }
                        }
                    }
                }
            }
        }
    }
    cend(ans);
    system("pause");
    return 0;
}
