#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)

#define ll long long
#define ull unsigned long long

#define csp(n) cout << n << " "
#define cend(n) cout << n << endl
#define cendl cout << endl
#define ctest cout << "test   "

const ll inf = 1e18;
using namespace std;

ll tt, ttt;
ll n,k,m,d,t,x,y,z,h, q;

#define node array<ll, 10>
ll primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
ll divmin[10000];
ull base = 13331;
set<ull> rec;
ull gethash(node & o){
	ll ret = 0;
	for(auto x : o){
		ret *= base;
		ret += x;
	}
	return ret;
}
bool outbound(node & o){
	ll cnt = 0;
	for(auto x : o){
		cnt += x;
	}
	if(cnt >= 31)return true;
	return false;
}
ll cntdiv(node & o){
	ll cnt = 1;
	for(auto x : o){
		cnt *= (x + 1);
	}
	return cnt;
}
void printnode(node & o){
	rep(i,10){
		csp(o[i]);
	}
	cendl;
}
void dfs(node o, ll x){
	if(outbound(o))return;
	if(x > n + 5)return;
	ull thehash = gethash(o);
	if(rec.count(thehash))return;
	rec.insert(thehash);
	ll divcnt = cntdiv(o);
	if(x < divmin[divcnt] && divcnt > 900){
		ctest;csp(x);cend(divcnt);
		printnode(o);
	}
	divmin[divcnt] = min(divmin[divcnt], x);
	rep(i,10){
		node u = o;
		if(i == 0){
			u[0]++;
			dfs(u, x * primes[0]);
		}
		else{
			if(u[i] < u[i - 1]){
				u[i]++;
				dfs(u, x * primes[i]);
			}
		}
	}
}

void sol(){
	rep(i,10000){
		divmin[i] = inf;
	}
	cin>>n;
	node sto;
	rep(i,10){
		sto[i] = 0;
	}
	dfs(sto, 1);
	ll ans = 0;
	rep(i,10000){
		if(divmin[i] != inf && divmin[i] <= n){
			ans = divmin[i];
		}
	}
	cend(ans);

}

int main(){

	tt = 1;
	for(ttt = 1;ttt <= tt;ttt++){
		sol();
	}
	system("pause");
	return 0;
}