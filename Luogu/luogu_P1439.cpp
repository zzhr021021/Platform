#include<bits/stdc++.h> 
using namespace std;
int n;
int ar1[100005], ar2[100005];
int dp[100005];
int main(){
	cin >> n;
	for(int i = 0;i < n;i++)cin >> ar1[i];
	for(int i = 0;i < n;i++)cin >> ar2[i];
	for(int i = 1;i <= n;i++){
		for(int j = n;j >= 1;j--){
			if(ar1[i - 1] == ar2[j - 1]){
				dp[j] = dp[j - 1] + 1;
			}
			else{
				dp[j] = dp[j - 1];
			}
		}
	}
	
	cout << dp[n];
	return 0;
}
