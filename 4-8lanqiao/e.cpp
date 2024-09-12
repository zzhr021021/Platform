#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include <vector>
#include <map>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;
vector<int> vocarr[20000];
int color[10000];
int father[10000];

int tempcount[205];
int soncount[205];

int result = 0;

int dfs(int node){
	int m[205];
	memset(m, 0, sizeof(m));
	m[color[node]]++;
	for(int i = 0;i < vocarr[node].size();i++){
		dfs(vocarr[node][i]);
		for(int i = 0;i < 202;i++){
			m[i] += soncount[i];
		}
	}
	int piv = 0;
	for(int i = 0;i < 203;i++){
		if(m[i] != 0){
			piv = m[i];
			break;
		}
	}
	for(int i = 0;i < 202;i++){
		if(m[i] != 0 && m[i] != piv){
			result++;
			break;
		}
	}
	for(int i = 0;i < 202;i++){
		soncount[i] = m[i];
	}
	return 1;
}
int main(){
	int n;
	cin >> n;
	
	for(int i = 1;i <= n;i++){
		cin >> color[i] >> father[i];
		vocarr[father[i]].push_back(i);
	}
	int test = 4;
	int temp;
	temp = dfs(1);
	
	
	
	cout << n - result;
	return 0;
	
}

