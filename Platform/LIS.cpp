#include<bits/stdc++.h>
using namespace std;
//for distinct sorted array, find a element index, return -1 if not in
//example test1[7] = {1,3,4,5,7,9,14};
//bifind(7) = 4
//bifind(8) = -1

int bifindrightbig(int a[], int l, int r, int tar){
	//cout << l << "  " << r <<  "  " << a[l] << "  " << tar << endl;
	if(l > r){
		return -1;
	}
	if(tar < a[l]){
		return -1;
	}
	if(tar >= a[r]){
		return r;
	}
	if(l == r && a[l] <= tar){
		return l;
	}
	if(l == r && a[l] > tar){
		return -1;
	}
	int m = (l + r) / 2;
	if(a[m] < tar){
		return bifindrightbig(a, m, r - 1, tar);
	}
	else if(a[m] == tar){
		return bifindrightbig(a, m, r - 1, tar);
	}
	else{
		return bifindrightbig(a, l, m - 1, tar);
	}
}

int LIS(int a[], int l, int r){
	if(l > r)return -1;
	int ascend[r + 5];
	int result[r + 5];
	if(l == r)return 1;
	ascend[0] = a[l];
	
	result[l] = 1;
	int pointer = 1;
	
	for(int i = l + 1;i <= r;i++){
		if(a[i] < ascend[0]){
			ascend[0] = a[i];
			result[i] = 1;
		}
		else{
			int tar = a[i];
			int j = bifindrightbig(ascend, 0, pointer - 1, tar);
			//cout << j << endl;
			if(j == pointer - 1){
				ascend[pointer] = a[i];
				result[i] = pointer + 1;
				pointer++;
			}
			else{
				ascend[j + 1] = a[i];
				result[i] = j + 2;
			}
		}
	}
	
	
	
	
	return pointer;
	
}
int main(){
	int n = 11;
	//cout << bifind(test1, 0, 6, n);
	int test2[n] =  {5,3,4,4,7,3,6,11,8,5,11};
    cout << LIS(test2, 0, 10);   
    
    
	return 0;
}
