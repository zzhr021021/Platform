#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)

using namespace std;

typedef long long ll;
const ll MMint = 1e6+5;
bool isp[MMint];
int primes[MMint];
int pp = 0;
int minprime[MMint];
int miu[MMint]; // mobius function

void sol(){
	
	
}
int main() {
	// Sieve of Eratosthenes
	for(int i = 0;i < MMint;i++){
		isp[i] = true;
		minprime[i] = i;
	}
	isp[0] = isp[1] = false;
	for(int i = 2;i < MMint;i++){
		if(isp[i]){
			primes[pp] = i;
			pp++;
		}
		for(int j = 0;j < pp;j++){
			int p = primes[j];
			int mul = i * p;
			if(mul < MMint){
				isp[mul] = false;
				minprime[mul] = p;
			}
			else{
				break;
			}
			if(i % p == 0){
				break;
			}
		}
	}
//	for(int i = 0;i < 10000;i++){
//		cout << primes[i] << "  ";
//	}
//	cout << endl;
//	for(int i = 0;i < 200;i++){
//		cout << i << "  " << minprime[i];
//		cout << endl;
//	}
//
//	cout << "prime number count : " << pp << endl;
	return 0;
}
