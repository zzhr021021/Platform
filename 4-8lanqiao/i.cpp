#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int n = 0, m = 0;
int board[12][12];
string strs[20];
long long state = 0;

void fillboard(){
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			board[i][j] = 0;
		}
	}
	int a = 0, b = 0;
	long long k = state;
	while(k != 0){
		board[a][b] = (k & 1);
		k = k >> 1;
		b++;
		if(b == m){
			b = 0;
			a++;
		}
	}
}
void prboard(){
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			cout << board[i][j];
		}
		cout << endl;
	}
}
bool isacc(){
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			if(strs[i][j] == '_'){
				continue;
			}
			else{
				int fin = strs[i][j] - '0';
				int mup = i - 1;
				int mdo = i + 1;
				int ml = j - 1;
				int mr = j + 1;
				if(i == 0)mup = i;
				if(i == n - 1)mdo = i;
				if(j == 0)ml = j;
				if(j == n + 1)mr = j;
				int co = 0;
				for(int ti = mup;ti <= mdo;ti++){
					for(int tj = ml; tj <= mr; tj++){
						if(board[ti][tj] == 1){
							co++;
						}
					}
				}
				if(co != fin)return false;
			}
		}
	}
	
	
	return true;
}
int main(){
	cin >> n >> m;
	
	for(int i = 0;i < n;i++)cin >> strs[i];
	
	
	if(n * m < 40){
		
		while(!isacc() && state < 1000000000000l){
			fillboard();
			//cout << endl << endl;
			state++;
			//prboard();
			//cout << state << "  ";
			//if(state % 100000 == 0)cout << state << endl;
		}
	}
	else{
		
	}
	prboard();
	
	
	return 0;
}

