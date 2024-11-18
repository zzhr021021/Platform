#include<bits/stdc++.h>
#define rep(i,n)for(int i = 0;i < n;i++)
#define ctest cout << "test   "
#define cend(x) cout << x << endl
#define csp(x) cout << x << " "
#define cendl cout << endl
#define ll long long 
#define vll vector<long long>

using namespace std;
ll n,m,k,d;
ll Q[10050][30];
ll Kt[30][10050];
ll V[10050][30];
ll W[10050];

ll M1[10050][30];
ll M2[10050][30];
ll M3[10050][30];

int main(int argc, char const *argv[])
{
    cin>>n>>d;
    rep(i,n){
        rep(j,d)cin>>Q[i][j];
    }
    rep(i,n){
        rep(j,d)cin>>Kt[j][i];
    }
    rep(i,n){
        rep(j,d)cin>>V[i][j];
    }
    rep(i,n)cin>>W[i];

    rep(i,d){
        rep(j,d){
            rep(ii, n){
                M1[i][j] += Kt[i][ii] * V[ii][j];
            }
        }
    }
    rep(i,n){
        rep(j,d){
            rep(ii, d){
                M2[i][j] += Q[i][ii] * M1[ii][j];
            }
        }
    }
    rep(i,n){
        rep(j,d){
            M2[i][j] *= W[i];
        }
    }
    rep(i,n){
        rep(j,d){
            csp(M2[i][j]);
        }
        cendl;
    }

    system("pause");


}
