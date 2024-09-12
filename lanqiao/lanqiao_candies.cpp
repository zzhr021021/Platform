#include<bits/stdc++.h>
using namespace std;
int N = 1 << 21;
int n, m, k;
int temp2;
int candy[200][200];
int bis[2000];
int dp[1 << 21];
int tobi(int k){
	int result = 1;
	return result << (k - 1);
}
int main(){
	for(int i = 0;i < N;i++){
		dp[i] = 10000000;
	}
	cin >> n >> m >> k;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < k;j++){
			cin >> temp2;
			bis[i] = bis[i] | tobi(temp2);
		}
	}
	
	for(int i = 0;i < n;i++){
		dp[bis[i]] = 1;
		for(int j = (1 << m) - 1;j >= 0;j--){
			dp[j | bis[i]] = min(dp[j | bis[i]], dp[j] + 1);
		}
	}
	if(dp[(1 << m) - 1] == 10000000){
		cout << "-1" << endl;
		return 0;
	}
	cout << dp[(1 << m) - 1] << endl;
	
	return 0;
}
