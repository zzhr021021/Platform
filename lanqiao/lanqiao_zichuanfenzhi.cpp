#include<bits/stdc++.h>
using namespace std;
string s;
int n;
int mystack[100205];
int pointer = 0;
int result = 0;
int main()
{
    cin >> s;
    n = s.length();
    for(int i = 0;i < 26;i++){
    	pointer = 0;
    	char a = 'a' + i;
    	//cout << a;
    	for(int i = 0;i < n;i++){
    		if(s[i] == a){
    			mystack[pointer] = i;
    			pointer++;
			}
		}
		//cout << pointer;
		if(pointer == 0){
			continue;
		}
		else if(pointer == 1){
			result += (mystack[0] + 1) * (n - mystack[0]);
			continue;
		}
    	for(int i = 0;i < pointer;i++){
    		int x ,y;
    		if(i == 0){
    			x = mystack[0] + 1;
    			y = mystack[1] - mystack[0];
			}
			else if(i == pointer - 1){
				x = mystack[i] - mystack[i - 1];
				y = n - mystack[i];
			}
			else{
				x = mystack[i] - mystack[i - 1];
				y = mystack[i + 1] - mystack[i];
			}
			result += x * y;
		}
	}
    
    cout << result;
    return 0;
}
