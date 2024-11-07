#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < n;i++)
using namespace std;

struct NODE{
	int val;
	vector<pair<int, int>> seq;
};

int main(){
	// testcase 1 : 7 30 35 15 5 10 20 25
	// testcase 2 : 9 10 100 5 50 30 20 60 45 50
	int n;
	cin>>n;
	vector<int> p;
	for(int i = 0;i < n;i++){
		int x;cin>>x;p.push_back(x);
	}
	vector<vector<NODE>> dp(n + 1, vector<NODE> (n + 1));
	rep(i,n + 1){
		rep(j,n + 1)dp[i][j].val = 1e9;
	}
	int m = n - 1;
	for(int gap = 1;gap <= m;gap++){
		for(int i = 0;i < m + 1 - gap;i++){
			int j = i + gap - 1;
			if(i == j){
				dp[i][j].val = 0;continue;
			}
			for(int k = i;k < j;k++){
				int tp = dp[i][k].val + dp[k + 1][j].val + p[i] * p[k + 1] * p[j + 1];
				if(tp < dp[i][j].val){
					dp[i][j].val = tp;
					dp[i][j].seq.clear();
					for(auto o : dp[i][k].seq){
						dp[i][j].seq.push_back(o);
					}
					for(auto o : dp[k + 1][j].seq){
						dp[i][j].seq.push_back(o);
					}
					dp[i][j].seq.push_back({i, j});
				}
			}
		}
	}

	cout << dp[0][m - 1].val << endl;
	int cnt = 0;
	for(auto o : dp[0][m - 1].seq){
		cnt++;
		cout << "Bracket " << cnt << " : " << o.first <<  "  " << o.second << endl;
	}
	cout << endl;

	system("pause");
	return 0;
}