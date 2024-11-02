#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)

#define ll long long
#define vll vector<long long>

#define csp(n) cout << n << " "
#define cend(n) cout << n << endl
#define cendl cout << endl
#define ctest cout << "test   "
 
const ll MOD = 1e9+7;
ll p = MOD;
using namespace std;
 
ll tt;
ll ttt;
ll n,k,m,d,q,t,x,y,z,h;

#define NODE array<array<ll, 3>, 3>

NODE idm {{
    {1, 0, 0},
    {0, 1, 0},
    {0, 0, 1}}
};

NODE matmul(NODE m1, NODE m2){
	NODE ret;
	rep(reti, 3){
		rep(retj, 3){
			ll tp = 0;
			rep(i,3){
				tp += m1[reti][i] * m2[i][retj];
				tp %= MOD;
			}
			ret[reti][retj] = tp;
		}
	}
	return ret;
}
void printmat(NODE & mat){
	rep(i,3){
		rep(j,3){
			csp(mat[i][j]);
		}
		cendl;
	}
}
NODE matexp(NODE mat, ll expo){
	if(expo == 0){
		return idm;
	}
	NODE ret = idm;
	if(expo & 1){
		ret = matmul(ret, mat);
	}
	NODE hlf = matexp(mat, expo / 2);
	ret = matmul(ret, hlf);
	ret = matmul(ret, hlf);
	return ret;
}



void sol(){
	cin>>n;
	ll expo = (n - 1) / 3;
	NODE base {{
		{1, 0, 1},
		{1, 1, 1},
		{1, 1, 2}}
	};
	NODE res = matexp(base, expo);
	ll ans = 0;
	n = (n - 1) % 3;
	rep(i,3){
		ans += res[n][i];
		ans %= MOD;
	}

	cend(ans);

}


int main(){
	// ios_base::sync_with_stdio(false);
	// cin.tie(nullptr);
	// cout.tie(nullptr);
		
	tt = 1;
	cin>>tt;
	for(ttt = 1;ttt <= tt;ttt++){
		sol();
	}
	return 0;
}