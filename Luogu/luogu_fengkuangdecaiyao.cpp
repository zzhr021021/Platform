#include<bits/stdc++.h>
using namespace std;
int t, m;
int ksl[10005][2];
long long dp[10000005];
int main(){
	cin >> t >> m;
	for(int i = 1;i <= m;i++){
		cin >> ksl[i][0] >> ksl[i][1];
	}
	
	for(int i = 1;i <= m;i++){
		for(int j = ksl[i][0];j <= t;j++){
				dp[j] = max(dp[j - ksl[i][0]] + ksl[i][1],   dp[j]);
			
			//cout << i << " " << j << " " << dp[j][i]  << " " << dp[j - ksl[j][0]][i - 1] <<endl;
		}
	}
	
	
	cout << dp[t];
	return 0;
}
