#include<bits/stdc++.h>
#define rep(i,n)for(int i = 0;i < n;i++)
#define ctest cout << "test   "
#define cend(x) cout << x << endl
#define csp(x) cout << x << " "
#define cendl cout << endl
#define ll long long 
#define vll vector<long long>

using namespace std;
ll n,m,k;
ll t[200005];
ll c[200005];

int main(int argc, char const *argv[])
{
    cin>>n>>m>>k;
    ll mxt = 0;
    rep(i,n){
        cin>>t[i]>>c[i];
        mxt = max(mxt, t[i]);
    }
    ll l = k, r = mxt + 1;
    while(l != r){
        ll mid = (l + r) / 2;
        ll need = 0;
        // ctest;cend(mid);
        rep(i,n){
            if(mid < t[i]){
                need += (t[i] - mid) * c[i];
            }
        }
        if(need <= m)r = mid;
        else l = mid + 1;
    }
    cend(l);
    system("pause");
    return 0;
}
