#include<bits/stdc++.h>
#define ll long long
#define rep(i,n) for(int i = 0;i < n;i++)
#define rep0n(i,n) for(int i = 0;i <= n;i++)
#define ctest cout << "test  "
#define cend(x) cout << x << endl
#define csp(x) cout << x << " "
using namespace std;

ll sg[300][300];
ll cnt[500];
void init_sg(){
	for(int i = 2;i <= 6;i++){
		for(int j = 2;j <= 6;j++){
			if(i == 2 && j == 2)continue;
			if(i == 3 && j == 2)continue;
			if(i == 2 && j == 3)continue;
			memset(cnt, 0, sizeof(cnt));
			for(int k = 2;k <= i - 2;k++){
				ll tp = sg[k][j] ^ sg[i - k][j];
				cnt[tp]++;
				// ctest;csp(i);csp(j);cend(tp);
			}
			for(int k = 2;k <= j - 2;k++){
				ll tp = sg[i][k] ^ sg[i][j - k];
				cnt[tp]++;
			}
			rep(k,500){
				if(cnt[k] == 0){
					// ctest;ctest;csp(i);csp(j);cend(k);
					sg[i][j] = k;
					break;
				}
			}
		}
	}
}

ll n, m;
int main(){
	init_sg();
	while(cin>>n>>m && n != 0){
		// ctest;cend(sg[n][m]);
		if(sg[n][m] == 0)cout << "LOSE" << endl;
		else cout << "WIN" << endl;
	}
	system("pause");
	return 0;
}
