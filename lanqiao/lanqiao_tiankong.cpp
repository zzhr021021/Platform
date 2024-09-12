#include<bits/stdc++.h>
using namespace std;
int n;
long long added[1000];
int deep;
int maxn;
int getd(int n){
	int result = 0;
	while(n != 0){
		result++;
		n = n >> 1;
	}
	return result;
}
int result;
int main()
{
	int temp;
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> temp;
		added[getd(i)] += temp;
		if(getd(i) > deep){
			deep = getd(i);
		}
	}
	for(int i = 1;i <= deep;i++){
		if(added[i] > maxn){
			maxn = added[i];
			result = i;
		}
	}
	
	cout << result;
    return 0;
}
