#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
long long n,maxd,ans[N];
bool dfs(int k){
	if(k>maxd)return ans[k-1]==n;
	if(ans[k-1]*((long long)1<<(maxd-k+1))<n)return 0;//最优化剪枝：后面每一项最多是前一项的2倍 
	for(int i=0;i<k;i++)
		for(int j=i;j<k;j++){
			long long t=ans[i]+ans[j];
			if(t>n)break;//可行性剪枝：ans单调递增，如果t>n则后面的j都会大于n； 
			if(t<=ans[k-1])continue; //保证ans单调递增 
			ans[k]=t;
			if(dfs(k+1))return 1;
		}
	return 0;
}
int main(){
	ans[0]=1;
	while(scanf("%lld",&n)&&n){
		printf("1");
		for(maxd=0;;maxd++){
			if(dfs(1)){
				for(int i=1;i<=maxd;i++)
					printf(" %lld",ans[i]);
				printf("\n");
				break;
			}
		}
	}
    system("pause");
	return 0;
}