#include<bits/stdc++.h>
using namespace std;
int x, t, n;
int exi[200000];
bool issquare(int n){
	if(n == 1){
		return true;
	}
	for(int i = 1;i <= n / 2;i++){
		if(i * i == n){
			return true;
		}
	}
	return false;
}
bool isprime(int n){
	if(n == 2){
		return true;
	}
	for(int i = 2; i <= n / 2;i++){
		if(n % i == 0){
			return false;
		}
	}
	return true;
}
int root(int n){
	for(int i = 1;i <= n;i++){
		if(i * i == n){
			return i;
		}
	}
	return -1;
}
int main(){
	cin >> x >> t;
	if(x == 1){
		for(int bigi = 0;bigi < t;bigi++){
			cin >> n;
			if(n == 1){
				cout << "2 1 ";
			}
			else if(n % 2 == 1){
				cout << "0";	
			}
			else{
				cout << "2 ";
				for(int i = 1;i <= n / 2;i++){
					cout << n - 2 * (i - 1);
					cout << " ";
					cout << i * 2 - 1;
					cout << " ";
				}
			}
			cout << endl;
		}
	}
	else{
		for(int bigi = 0;bigi < t;bigi++){
			cin >> n;
			if(n == 4){
				cout << "1 3 2 4";
			}
			else if(isprime(n)){
				
			}
			else{
				cout << "0";
			}
			cout << endl;
		}
	}
	
	
	return 0;
}
