#include<bits/stdc++.h>
using namespace std;
int n;
int sco[10005];
int maxs, mins = 105, adds;
bool isrun(int x){
	if(x % 400 == 0){
		return true;
	}
	if(x % 100 == 0){return false;
	}
	if(x % 4 == 0)return true;
	return false;
}
int main(){
    cin >> n;
    for(int i = 0;i < n;i++){
    	cin >> sco[i];
    	if(sco[i] > maxs){
    		maxs = sco[i];
		}
		if(sco[i] < mins){
			mins = sco[i];
		}
		adds += sco[i];
	}
	cout << maxs << endl << mins << endl;
	printf("%.2lf", adds * 1.0 / n);
	
}

