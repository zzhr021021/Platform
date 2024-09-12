#include<bits/stdc++.h>
using namespace std;
long long n, k;

long long g(int n, int k){
	if(n > k){
		return g(k, k) + (n - k) * k;
	}
	long long temp;
	
	return 0;
}
int main(){
	cin >> n >> k;
	
	
	
	cout << g(n, k);
	return 0;
}
