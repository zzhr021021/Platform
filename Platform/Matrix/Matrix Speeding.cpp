#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)

#define ll long long
#define ull  long long
#define vll vector<long long>

#define csp(n) cout << n << " "
#define cend(n) cout << n << endl
#define cendl cout << endl
#define ctest cout << "test   "
using namespace std;

#define VELEN 12
const ll p = 1e7 + 7;

ll tt;
ll ttt;
ll n,k,m,d,q,t,x,y,z,h;

#define VEC array<ull, VELEN>
#define NODE array<array<ull, VELEN>, VELEN>
void printvec(VEC & o){
	rep(i,VELEN){
        csp(o[i]);
	}
    cendl;
}
void printmat(NODE & mat){
	rep(i,VELEN){
		rep(j,VELEN){
			csp(mat[i][j]);
		}
		cendl;
	}
}
void clearvec(VEC & o){
    rep(i,VELEN)o[i] = 0;
}
void clearmat(NODE & o){
    rep(i,VELEN){
		rep(j,VELEN){
			o[i][j] = 0;
		}
	}
}

NODE idm;

NODE matmul(NODE m1, NODE m2){
	NODE ret;
	rep(reti, VELEN){
		rep(retj, VELEN){
			ll tp = 0;
			rep(i,VELEN){
				tp += m1[reti][i] * m2[i][retj] % p;
				tp %= p;
			}
			ret[reti][retj] = tp;
		}
	}
	return ret;
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

VEC transform(NODE & mat, VEC vec){
    VEC ret;
    rep(i,VELEN){
        ll tp = 0;
        rep(j,VELEN){
            tp += mat[i][j] * vec[j] % p;
			tp %= p;
        }
        ret[i] = tp;
    }
    return ret;
}

void sol(){
    while(cin>>n){
		cin>>m;
		// get identity
		rep(i,VELEN){
			rep(j,VELEN){
				idm[i][j] = 0;
				if(i == j)idm[i][j] = 1;
			}
		}
		
		VEC st;
		rep1n(i,n)cin>>st[i];
		st[0] = 23;
		st[11] = 1;

		NODE step;
		clearmat(step);
		rep(i,11){
			step[i][0] = 10;
			step[i][11] = 3;
		}
		rep1n(i,10){
			for(int j = 1;j <= i;j++){
				step[i][j] = 1;
			}
		}
		step[11][11] = 1;

		NODE trans = matexp(step, m);
		VEC ans = transform(trans, st);
		cend(ans[n]);
	}
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