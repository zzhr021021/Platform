#include<bits/stdc++.h>
using namespace std;
int n;
int father[200000];
int sonnum[200000];
vector<int> sons[100005];
int gethei(int n){
	if(sonnum[n] == 0){
		return 1;
	}
	int si = sons[n].size();
	int temp[si];
	int maxx = 0;
	for(int i = 0;i < si;i++){
		temp[i] = gethei(sons[n][i]);
		if(temp[i] > maxx){
			maxx = temp[i];
		}
	}
	
	
	return maxx + sons[n].size();
}
int main(){
	cin >> n;
	for(int i = 2;i <= n;i++){
		cin >> father[i];
		sonnum[father[i]]++;
		sons[father[i]].push_back(i);
	}
	
	
	cout << gethei(1) - 1;
	return 0;
}
