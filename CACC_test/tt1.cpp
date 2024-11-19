#include<bits/stdc++.h>
#define rep(i,n)for(int i = 0;i < n;i++)
#define rep1n(i,n)for(int i = 1;i <= n;i++)
#define ctest cout << "test   "
#define cend(x) cout << x << endl
#define csp(x) cout << x << " "
#define cendl cout << endl
#define ll long long 
#define vll vector<long long>

using namespace std;
ll n,m,k,d;
ll a[100050];
map<ll, ll> cnt;
set<ll> c1;

int main(int argc, char const *argv[])
{
    cin>>n>>k;
    a[0] = -1;
    rep1n(i,n)cin>>a[i];
    for(int i = 0;i < k;i++){
        cnt[a[i]]++;
        if(cnt[a[i]] == 1){
            c1.insert(a[i]);
        }
        else if(cnt[a[i]] <= 2){
            c1.erase(a[i]);
        }
    }
    
    for(int i = k;i <= n;i++){
        cnt[a[i]]++;
        if(cnt[a[i]] == 1){
            c1.insert(a[i]);
        }
        else if(cnt[a[i]] <= 2){
            c1.erase(a[i]);
        }
        
        cnt[a[i - k]]--;
        if(cnt[a[i - k]] == 1){
            c1.insert(a[i - k]);
        }
        else if(cnt[a[i - k]] <= 2){
            c1.erase(a[i - k]);
        }
        if(c1.size() == 0){
            csp(-1);
        }
        else{
            auto p = c1.end();
            p--;
            csp(*p);
        }
    }


    system("pause");


}
