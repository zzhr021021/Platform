#include<bits/stdc++.h>
#define ll long long
#define rep(i,n) for(int i = 0;i < n;i++)
#define rep0n(i,n) for(int i = 0;i <= n;i++)
#define ctest cout << "test  "
#define cend(x) cout << x << endl
#define csp(x) cout << x << " "
using namespace std;

ll sg[2000];
ll cnt[2000];
void init_sg(){
	sg[1] = 0;
	for(int i = 2;i <= 1000;i++){
		memset(cnt, 0, sizeof(cnt));
		ll xr = 0;
		for(int j = 1;j < i;j++){
			if(i % j == 0){
				xr ^= sg[j];
			}
		}
		for(int j = 1;j < i;j++){
			if(i % j == 0){
				cnt[xr ^ sg[j]]++;
			}
		}
		rep(j,1005){
			if(cnt[j] == 0){
				sg[i] = j;
				break;
			}
		}
	}
}

ll a[150];
ll n;
int main(){
	init_sg();
	while(cin>>n && n != 0){
		rep(i,n)cin>>a[i];		

		ll xr = 0;
		rep(i,n){
			xr ^= sg[a[i]];
		}
		if(xr)cend("freda");
		else cend("rainbow");
	}
	system("pause");
	return 0;
}

