#include<bits/stdc++.h>
using namespace std;

// if tar in a, return {pos of tar, pos of tar}
// in tar not in a, return {x, y}:
// x : pos of last element smaller than tar
// y : pos of first element bigger than tar)
pair<int, int> bifindrightbig(int a[], int l, int r, int tar){
	if(l > r){
		return {-1, -1};
	}
    if(tar < a[l]){
        return {l - 1, l};
    }
    if(tar > a[r]){
        return {r, r + 1};
    }
    if(tar == a[l]){
        return {l, l};
    }
    if(tar == a[r]){
        return {r, r};
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
	int a[12] =  {1,2,2,3,4,4,4,7,7,8,9,10};
    auto o = bifindrightbig(a, 0, 11, 4);
    cout << "4 is in array" << endl;
	cout << o.first << " " << o.second << endl;
    o = bifindrightbig(a, 0, 11, 5);
    cout << "5 is not in array" << endl;
	cout << o.first << " " << o.second << endl;
	system("pause");
	return 0;
}
