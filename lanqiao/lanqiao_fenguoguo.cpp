#include<bits/stdc++.h>
using namespace std;
int n, m;
int w[300];
int sumfromto[105][105];
int main(){
	cin >> n >> m;
	for(int i = 0;i < n;i++){
		cin >> w[i];
	}
	if(m == 1 || m == 2){
		cout << "0";
	}
	w[n] = -10000000;
	for(int i = n + 1;i < n + 1 + n;i++){
		w[i] = w[i - n - 1];
	}
	
	
	return 0;
}
