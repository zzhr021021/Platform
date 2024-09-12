#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;


int main(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0;i < n;i++)cin >> a[i];
	long long result = 0;
	for(int i = 0;i < n;i++){
		int tmepoxr = 0;
		for(int j = i;j < n;j++){
			tmepoxr ^= a[j];
		}
		result += tmepoxr
	}
	
	cout << result;
}

