#include<cstdio>
#include<iostream>
using namespace std;

int getdigit(int k){
	int result = 0;
	while(k != 0){
		result++;
		k /= 10;
	}
	return result;
}

int digitadd(int k){
	int result = 0;
	while(k != 0){
		result += k % 10;
		k /= 10;
	}
	return result;
}
bool islucky(int k){
	int d = getdigit(k);
	if(d % 2 == 1)return false;
	d /= 2;
	int ten = 1;
	for(int i = 1;i <= d;i++){
		ten *= 10;
	}
	int a = k % ten;
	int b = k / ten;
	if(digitadd(a) == digitadd(b))return true;
	return false;
}
int main(){
	cout << islucky(3) << endl;
	cout << islucky(334) << endl;
	cout << islucky(35125) << endl;
	cout << islucky(3456) << endl;
	cout << islucky(34899852) << endl;
	cout << islucky(2314) << endl;
	int result = 0;
	for(int i = 1;i <= 100000000;i++){
		if(islucky(i))result++;
	}
	cout << result << endl;
	return 0;
}
