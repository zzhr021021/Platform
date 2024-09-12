#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)

typedef long long ll;
const ll MMint = 1e6+5;
using namespace std;



void sol(){
	
	
}


ll less_than(vll & vec, ll val){
	ll l = 0, r = vec.size() - 1;
	while(l != r){
		ll mid = (l + r + 1) / 2;
		if(vec[mid] < val){
			l = mid;
		}
		else{
			r = mid - 1;
		}
	}
	return vec[l];
}

ll less_equal_than(vll & vec, ll val){
	ll l = 0, r = vec.size() - 1;
	while(l != r){
		ll mid = (l + r + 1) / 2;
		if(vec[mid] <= val){
			l = mid;
		}
		else{
			r = mid - 1;
		}
	}
	return vec[l];
}

int main() {
	int a[]={1,2,3,4,5,7,8,9};
	// first big or equal location
	printf("%d\n",lower_bound(a,a+8,6)-a);
	// last big or equal location
	printf("%d\n",upper_bound(a,a+8,10)-a); 
	
	
	vector<ll> vec({1,2,3,6,9,10,15,20});
	 
	return 0;
}
