#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;


int main(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 1;i <= n;i++)cin >> a[i];
	long long result = 0;
	for(int i = 0;i < 5;i++){
		int mystack[n + 4];
		int rec[n + 4];
		int pointer = 0;
		long long toadd = (1 << i);
		cout << "thisscope toadd:" << toadd << endl;
		int lastzero = 0;
		for(int j = 1;j <= n;j++){
			//cout << ((a[j] >> i) & 1);
			
		}
		for(int j = 1;j <= n;j++){
			
			
			if(((a[j] >> i) & 1) == 1){
				mystack[pointer] = j;
				pointer++;
			}
			int temp = 0;
			if(((a[j] >> i) & 1) == 1){
				temp = 0;
				if(pointer == 1){
					temp += toadd * mystack[pointer - 1];
					rec[j] = temp;
				}
				else if(pointer == 2){
					temp += toadd *( mystack[pointer - 1] - mystack[pointer - 2]);
					rec[j] = temp;
				}
				else{
					temp += toadd *( mystack[pointer - 1] - mystack[pointer - 2]);
					temp += rec[mystack[pointer - 3]];
					rec[j] = temp;
				}
				result += temp;
			}
			else{
				if(pointer == 0)continue;
				rec[j] = rec[mystack[pointer - 1]];
				result += rec[j];
				temp = rec[j];
			}
			cout << "stalen" << pointer << endl;
			cout << temp << endl;
		}
		
		cout << endl;
	}
	
	cout << result;
	return 0;
}

