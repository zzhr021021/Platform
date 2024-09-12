#include<bits/stdc++.h>
using namespace std;
int t, m;
int ksl[20000][2];
int dp[12890];
int main(){
	cin >> m >> t;
	for(int i = 1;i <= m;i++){
		cin >> ksl[i][0] >> ksl[i][1];
	}
	
	for(int i = 1;i <= m;i++){
		for(int j = t;j >= 0;j--){
			if(j - ksl[i][0] >= 0){
				dp[j] = max(dp[j - ksl[i][0]] + ksl[i][1],   dp[j]);
			}
			else{
				dp[j] = dp[j];
			}
			
			//cout << i << " " << j << " " << dp[j][i]  << " " << dp[j - ksl[j][0]][i - 1] <<endl;
		}
	}
	
	
	cout << dp[t];
	return 0;
}
