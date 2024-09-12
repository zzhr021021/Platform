#include<cstdio>
#include<iostream>
#include<cstring>
#include <algorithm>
using namespace std;

bool bigger(string temp, string retemp){
	int tl = temp.length();
	for(int i = 0;i < tl;i++){
		if(retemp[i] > temp[i]){
			return true;
		}
		if(retemp[i] < temp[i]){
			return false;
		}
	}
	
	return false;
}
int main(){
	string n;
	cin >> n;
	int len = 0;
	len = n.length();
	int result = 0;
	for(int i = 0;i < len;i++){
		for(int j = i + 1;j < len;j++){
			string temp = n.substr(i, j + 1);
			
			string retemp(temp.size(), ' ');
			
			reverse_copy(temp.begin(), temp.end(), retemp.begin());
			
			if(bigger(temp, retemp)){
				result++;
			}
		}
	}
	
	
	cout << result;
	return 0;
}

