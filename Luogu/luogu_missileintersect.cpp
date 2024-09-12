#include<bits/stdc++.h> 
using namespace std;
int missile[100005];
int dp[100005];
int sys[100005];
int spoi;
int pointer = 0;
char s[700000] = { };
bool mc(pair<int, int> a, pair<int, int> b){
	if(a.first > b.first){
		return true;
	}
	if(a.first < b.first){
		return false;
	}
	if(a.second > b.second){
		return true;
	}
	return false;
}
int main(){
	cin.getline(s, 700000);
	for(int i = 0;i < 700000;i++){
		if(s[i] == ' '){
			pointer++;
		}
		else if(s[i] >= '0' && s[i] <= '9'){
			int num = s[i] - '0';
			missile[pointer] *= 10;
			missile[pointer] += num;
		}
		else{
			pointer++;
			break;
		}
	}
	//cout << s << endl;
	for(int i = 0;i < pointer;i++){
		//cout << missile[i] << endl;
	}
	
	dp[0] = 1;
	for(int i = 1;i < pointer;i++){
		int result = 0;
		for(int j = 0;j < i;j++){
			if(missile[i] <= missile[j]){
				result = max(result, dp[j] + 1);
			}
		}
		result = max(1, result);
		dp[i] = result;
	}
	int maxn = 0;
	for(int i = 0;i < pointer;i++)if(dp[i] > maxn)maxn = dp[i];
	cout << maxn << endl;
	
//	pair<int, int> p[pointer];
//	for(int i = 0;i < pointer;i++){
//		p[i].first = missile[i];
//		p[i].second = i;
//	}
//	sort(p, p + pointer, mc);
//	for(int i = 0;i < pointer;i++){
//		cout << p[i].second << endl;
//	}
	for(int i = 0;i < pointer;i++){
		int flag = 0;
		for(int j = 0;j < spoi;j++){
			if(sys[j] >= missile[i]){
				sys[j] = missile[i];
				flag = 1;
				break;
			}
		}
		if(flag)continue;
		else{
			sys[spoi] = missile[i];
			spoi++;
		}
	}
	cout << spoi;
	return 0;
}
