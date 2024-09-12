#include<cstdio>
#include<iostream>
using namespace std;
bool isnotallowed(int k){
	while(k != 0){
		if((k & ((1 << 10) - 1)) == ((1 << 10) - 1)){
			return true;
		}
		k = k >> 1;
	}
	return false;
}
int st = 11;
int main(){
	int result = 0;
	int bigresult = 0;
	for(st = 0;st <= 22;st++){
		
		result = 0;
	for(int i = 0;i < (1 << st);i++){
		if(!isnotallowed(i)){
			result++;
		}
	}
	
	bigresult += result;
	cout << result << "    ";
	cout << bigresult << endl;
	}
	cout << bigresult + 1;
	return 0;
}
