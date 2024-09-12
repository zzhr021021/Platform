#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int x[300000];
int digit[30];
int digit2[30];
int getdigit(int bi){
	int res = 0;
	while(bi != 0){
		bi = bi >> 1;
		res++;
	}
	return res;
}
int main(){
	cin >> t;
	for(int bigi = 0;bigi < t;bigi++){
		for(int i = 0;i < 30;i++){
			digit[i] = 0;
			digit2[i] = 0;
		}
		cin >> n;
		for(int i = 0;i < n;i++){
			cin >> x[i];
		}
		sort(x, x + n);
		
		int temp = 0;
		for(int i = 0;i < n;i++){
			temp = temp ^ x[i];
		}
		if(temp == 0){
			puts("0");
			continue;
		}
		
		for(int i = 0;i < n;i++){
			int mea = 1;
			for(int j = 0;j < 25;j++){
				if((x[i] & mea) != 0){
					digit[j]++;
				}
				else{
					digit2[j]++;
				}
				mea = mea << 1;
			}
		}
		for(int i = 0;i < 10;i++){
			//cout << digit[i] << "---" << digit2[i] << endl;
		}
		for(int i = 24;i >= 0;i--){
			if(digit[i] == 1){
				puts("1");
				break;
			}
			else if(digit[i] % 2 == 0 || digit[i] == 0){
				continue;
			}
			else if(digit2[i] % 2 == 0){
				puts("1");
				break;
			}
			else{
				puts("-1");
				break;
			}
		}
		
		
		
	}
	return 0;
}
