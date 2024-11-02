#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int base = 1000000000;
const int base_digits = 9;
const ll fullbit = -1;
struct ll128 {
    array<ll, 2> a; // make a[0] high, a[1] low;

	ll128(){
		a[0] = a[1] = 0;
    }
	ll128(long long v) {
		if(v >= 0){
			a[1] = v;
		}
		else{
			v = -v;
			a[0] = a[1] = fullbit;
			a[1] -= v - 1;
		}
    }
    // ll128(const string &s) {
    //     read(s);
    // }
	void operator=(const ll128 &v) {
		a[0] = v.a[0];
		a[1] = v.a[1];
    }
    void operator=(long long v) {
		if(v >= 0){
			a[1] = v;
		}
		else{
			v = -v;
			a[0] = a[1] = fullbit;
			a[1] -= v - 1;
		}
    }
	


};

int main(int argc, char const *argv[]){
    cout << "test  ";
    ll128 x = 37;
    ll128 y = 109;
	
    system("pause");
    return 0;
}
