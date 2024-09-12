#include<bits/stdc++.h>
using namespace std;
int result[3000005];
void getRightBiggerLoc(int res[], int nums[], int n){
	int myindstack[3000005];
	int pointer = 0;
	for(int i = 0;i < n;i++){
		while(pointer != 0 && nums[i] > nums[myindstack[pointer - 1]]){
			pointer--;
			res[myindstack[pointer]] = i;
		}
		myindstack[pointer] = i;
		pointer++;
	}
	
}
int nums[3000005];
int main(){
	int n;
	cin >> n;
	for(int i = 0;i < n;i++)cin >> nums[i];
	getRightBiggerLoc(result, nums, n);
	for(int i = 0;i < n;i++)if(result[i] == 0)result[i]--;
	for(int i = 0;i < n;i++)cout << result[i]  + 1<< " ";
	return 0;
}
