#include<bits/stdc++.h>
using namespace std;
int test1[7] = {1,3,4,5,7,9,14};
//for distinct sorted array, find a element index, return -1 if not in
//example test1[7] = {1,3,4,5,7,9,14};
//bifind(7) = 4
//bifind(8) = -1
int bifind(int a[], int l, int r, int tar){
	if(l > r){
		return -1;
	}
	if(tar < a[l] || tar > a[r]){
		return -1;
	}
	if(l == r && a[l] == tar){
		return l;
	}
	if(l == r && a[l] != tar){
		return -1;
	}
	int m = (l + r) / 2;
	if(a[m] > tar){
		return bifind(a, l, m - 1, tar);
	}
	else if(a[m] == tar){
		return m;
	}
	else{
		return bifind(a, m + 1, r, tar);
	}
} 
//for not distinct sorted array, find a element index, return -1 if not in
//example test1[11] = {1,3,4,5,7,7,7,7,7,9,14};
//bifind(7) = 4
//bifind(8) = -1
int bifindfirst(int a[], int l, int r, int tar){
	if(l > r){
		return -1;
	}
	if(tar < a[l] || tar > a[r]){
		return -1;
	}
	if(l == r && a[l] == tar){
		return l;
	}
	if(l == r && a[l] != tar){
		return -1;
	}
	int m = (l + r) / 2;
	if(a[m] > tar){
		return bifindfirst(a, l, m - 1, tar);
	}
	else if(a[m] == tar){
		return bifindfirst(a, l, m, tar);
	}
	else{
		return bifindfirst(a, m + 1, r, tar);
	}
}

int bifindrightbig(int a[], int l, int r, int tar){
	cout << l << "  " << r << endl;
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
int main(){
	int n = 0;
	//cout << bifind(test1, 0, 6, n);
	int test2[8] =  {1,2,2,2,4,4,4,7};
	cout << bifindrightbig(test2, 0, 7, 4);
	
	return 0;
}
