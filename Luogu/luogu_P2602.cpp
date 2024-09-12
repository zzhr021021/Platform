#include <bits/stdc++.h>
using namespace std;
long long digits[10];
long long digits2[10];
long long getdigit(long long n){
	long long result = 0;
	while(n != 0){
		result ++;
		n /= 10;
	}
	return result;
}
long long getd(long long n, long long d){
	long long div = 1;
	for(long long i = 1;i < d;i++){
		div *= 10;
	}
	return (n / div) % 10;
}
long long mypowten(int n){
	long long result = 1;
	for(int i = 1;i <= n;i++){
		result *= 10;
	}
	return result;
}
void getn(long long n, long long arr[]){
	int d = getdigit(n);
	for(int i = d;i >= 1;i--){
		long long mid = getd(n, i);
		long long tempt = mypowten(i - 1);
		long long x = n / (tempt * 10);
		long long y = n % tempt;
		int num = getd(n, i);
		if(i == d){
			for(int j = 1;j < mid;j++){
				arr[j] += tempt;
			}
			arr[mid] += y + 1;
		}
		else{
			if(mid == 0){
				arr[0] += (x - 1) * tempt;
				arr[0] += y + 1;
				for(int j = mid + 1;j <= 9;j++){
					arr[j] += (x) * tempt;
				}
			}
			else{
				arr[0] += (x) * tempt;
				for(int j = 1;j < mid;j++){
					arr[j] += (x + 1) * tempt;
				}
				arr[mid] += y + 1;
				for(int j = mid;j <= 9;j++){
					arr[j] += (x) * tempt;
				}
			}
			
		}
		
	}
}
long long a, b;
int main(){
	cin >> a >> b;
	getn(b, digits);
	getn(a - 1, digits2);
	for(long long i = 0;i < 10;i++){
		cout << digits[i]  - digits2[i]<< " ";
	}
	return 0;
}
