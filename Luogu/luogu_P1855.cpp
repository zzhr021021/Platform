#include<bits/stdc++.h>
using namespace std;
int n, m, t;
int dp[300][300];
int mi[200];
int ti[200];

int main(){
	cin >> n >> m >> t;
	for(int i = 0;i < n;i++){
		cin >> mi[i] >> ti[i];
	}
	for(int i = 0;i < n;i++){
		for(int j = m;j >= 0;j--){
			for(int k = t;k >= 0;k--){
				if(j - mi[i] >= 0 && k - ti[i] >= 0)dp[j][k] = max(dp[j][k], dp[j - mi[i]][k - ti[i]] + 1);
			}
		}
	}
	
	cout << dp[m][t];
	return 0;
}
