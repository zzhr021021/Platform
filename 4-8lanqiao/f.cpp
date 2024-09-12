#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

int melon[40];
int main(){
	int n, m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> melon[i];
		melon[i] *= 2;
	}
	m *= 2;
	
	int dp[30][m + 5];
	for(int i = 0;i < 30;i++)dp[i][0] = 0;
	for(int i = 1;i < m + 5;i++)dp[0][i] = 0x3f3f3f3f;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			int minx = 0x3f3f3f3f;
			if(dp[i - 1][j] < minx){
				minx = dp[i - 1][j];
			}
			if(j - melon[i] >= 0 && dp[i - 1][j - melon[i]] < minx){
				minx = dp[i - 1][j - melon[i]];
			}
			if(j - melon[i] / 2 >= 0 && dp[i - 1][j - melon[i] / 2] + 1 < minx){
				minx = dp[i - 1][j - melon[i] / 2] + 1;
			}
			dp[i][j] = minx;
		}
	}
//	for(int i = 0;i <= n;i++){
//		for(int j = 0;j <= m;j++){
//			cout << dp[i][j] << "   ";
//		}
//		
//		cout << endl;
//	}
	
	cout << dp[n][m];
	return 0;
}

