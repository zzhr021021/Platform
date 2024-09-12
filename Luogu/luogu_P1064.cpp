#include<bits/stdc++.h>
using namespace std;
int n, m, mainm;
int ori0[100];
int ori1[100];
int ori2[100];
int price[5][100];
int value[5][100];
int bef[100];
int dp[33000];
int main(){
	memset(value, 0, sizeof(value));
	cin >> n >> m;
	
	for(int i = 0;i < m;i++){
		cin >> ori0[i] >> ori1[i] >> ori2[i];
		if(ori2[i] == 0)mainm++;
	}
	for(int i = 0;i < m;i++){
		if(ori2[i] == 0){
			price[0][i] += ori0[i];
			price[1][i] += ori0[i];
			price[2][i] += ori0[i];
			price[3][i] += ori0[i];
			value[0][i] += ori0[i] * ori1[i];
			value[1][i] += ori0[i] * ori1[i];
			value[2][i] += ori0[i] * ori1[i];
			value[3][i] += ori0[i] * ori1[i];
		}
		else{
			if(bef[ori2[i]] == 0){
				bef[ori2[i]] = 1;
				price[1][ori2[i] - 1] += ori0[i];
				price[3][ori2[i] - 1] += ori0[i];
				value[1][ori2[i] - 1] += ori0[i] * ori1[i];
				value[3][ori2[i] - 1] += ori0[i] * ori1[i];
			}
			else{
				bef[ori2[i]] = 1;
				price[2][ori2[i] - 1] += ori0[i];
				price[3][ori2[i] - 1] += ori0[i];
				value[2][ori2[i] - 1] += ori0[i] * ori1[i];
				value[3][ori2[i] - 1] += ori0[i] * ori1[i];
			}
		}
	}
	for(int i = 0;i < 10;i++){
		for(int j = 0;j < 4;j++){
			//cout << price[j][i] << "   ";
		}
		//cout << endl;
	}
	for(int i = 0;i < 10;i++){
		for(int j = 0;j < 4;j++){
			//cout << value[j][i] << "   ";
		}
		//cout << endl;
	}
	for(int i = 0;i < m;i++){
		for(int j = n;j >= 0;j--){
			for(int k = 0;k < 4;k++){
				if(j - price[k][i] >= 0){
					dp[j] = max(dp[j], dp[j - price[k][i]] + value[k][i]);
				}
			}
		}
	}
	int temp2 = 0;
	cout << dp[n];
	return 0;
}
