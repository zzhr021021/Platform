#include<cstdio>
#include<iostream>
using namespace std;

int proc(int k){
	if(k == 0)return 0;
	int result = 0;
	int a = (k + 1) / 2;
	int b = (k) / 4;
	return a + b;
}
int main(){
	int l,r ;
	cin >> l >> r;
	cout << proc(r) - proc(l - 1);
//	cout << proc(r);
}
