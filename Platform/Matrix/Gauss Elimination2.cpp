#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)

#define csp(n) cout << n << " "
#define cend(n) cout << n << endl
#define cendl cout << endl
#define ctest cout << "test   "
using namespace std;

const int p = 7, N = 305;

int tt, ttt;
int n,k,m,d,t,x,y,z,h,q;
/*
9 9
6 SUN SUN
1 8 4 2 4 8
6 SUN MON
5 6 5 7 1 9
11 THU THU
4 5 5 2 6 4 2 6 1 8 2
11 SUN SAT
4 3 2 9 8 1 4 2 1 8 7
8 THU TUE
2 9 2 6 5 4 9 8
9 WED THU
7 6 6 5 5 5 7 9 7
10 MON SUN
4 9 9 8 8 6 6 1 1 1
10 MON SAT
2 9 1 7 7 4 1 7 7 7
8 SAT SAT
6 7 3 8 4 8 7 2

ans : 
9 3 3 5 5 6 6 7 6
out : 
3 9 5 4 6 8 5 8 9
*/
int inv7[10] = {0,1,4,5,2,3,6,0,0,0};
char s1[5], s2[5];
int calc(char s[5]){
	if(s[0]=='M') return 1;
	if(s[0]=='T'&&s[1]=='U') return 2;
	if(s[0]=='W') return 3;
	if(s[0]=='T'&&s[1]=='H') return 4;
	if(s[0]=='F') return 5;
	if(s[0]=='S'&&s[1]=='A') return 6;
	return 7;
}

int c[N][N];
void printc(){
	cendl;
	rep(i,m){
		rep(j,n + 1){
			csp(c[i][j]);
		}
		cendl;
	}
	cendl;
}
void fiddle(int x, int y){
	if(y == n || x == m)return;
	int pos = -1;
	for(int i = x;i < m;i++){
		if(c[i][y] != 0){
			pos = i;
			break;
		}
	}
	if(pos == -1){
		fiddle(x, y + 1);
	}
	else{
		for(int j = y;j < n + 1;j++){
			swap(c[x][j], c[pos][j]);
		}
		int inv = inv7[c[x][y]];
		for(int j = 0;j < n + 1;j++){
			c[x][j] *= inv;
			c[x][j] %= 7;
		}
		for(int i = x + 1;i < m;i++){
			int tp = c[i][y];
			for(int j = 0;j < n + 1;j++){
				c[i][j] -= tp * c[x][j];
				c[i][j] %= 7;
				c[i][j] += 7;
				c[i][j] %= 7;
			}
		}
		// printc();
		fiddle(x + 1, y + 1);
	}
}


void solve(){
	memset(c, 0, sizeof(c));
	rep(i,m){
		cin>>k;
		cin>>s1>>s2;
		c[i][n] = calc(s2) - calc(s1) + 8;
		c[i][n] %= 7;
		rep(j,k){
			int tp;cin>>tp;
			c[i][tp - 1]++;
			c[i][tp - 1] %= 7;
		}
	}
	
	// printc();
	fiddle(0, 0);
	// printc();
	
	rep(i,m){
		int pos = -1;
		rep(j,n + 1){
			if(c[i][j]){
				pos = j;
				break;
			}
		}
		if(pos == n){
			cend("Inconsistent data.");
			return;
		}
	}
	if(n > m){
		cend("Multiple solutions.");
		return;
	}
	rep(i,n){
		if(c[i][i] == 0){
			cend("Multiple solutions.");
			return;
		}
	}
	for(int i = m - 1;i >= 0;i--){
		for(int j = n - 1;j >= 0;j--){
			if(c[i][j]){
				for(int k = i - 1;k >= 0;k--){
					c[k][n] -= c[i][n] * c[k][j];
					c[k][n] %= 7;
					c[k][n] += 7;
					c[k][n] %= 7;
					c[k][j] = 0;
				}
			}
		}
	}
	// printc();
	rep(i,n){
		int tp = c[i][n];
		if(tp < 3)tp += 7;
		if(i == n - 1)cend(tp);
		else csp(tp);
	}
}

void sol(){
	while(cin>>n>>m&&n){
		solve();

	}

}

int main(){
	// ios_base::sync_with_stdio(false);
	// cin.tie(nuintptr);
	// cout.tie(nuintptr);

	tt = 1;
	// cin>>tt;
	for(ttt = 1;ttt <= tt;ttt++){
		sol();
	}
	system("pause");
	return 0;
}