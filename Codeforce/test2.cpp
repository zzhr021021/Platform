#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)

#define csp(n) cout << n << " "
#define cend(n) cout << n << endl
#define cendl cout << endl
#define ctest cout << "test   "
#define pb push_back

using namespace std;

int tt, ttt;
int n,x,y,z;

int a[30];
bool v[30];
char s[4][30];
void printstate(){
	rep(i,3){
		rep(j,n){
			if(a[s[i][j]] == -1){
				csp(-1);
			}
			else{
				csp(a[s[i][j]]);
			}
		}
		cendl;
	}
	cendl;
}
bool dfs(int x, int y, int asd){
	if(x == -1){
		int tp = 0;
		while(a[tp] != -1){
			csp(a[tp]);
			tp++;
		}
		return true;
	}
	for(int i = x - 1;i >= 0;i--){
		if(a[s[0][i]] != -1 && a[s[1][i]] != -1 && a[s[2][i]] != -1){
			if(((a[s[0][i]] + a[s[1][i]]) % n != a[s[2][i]]) && ((a[s[0][i]] + a[s[1][i]] + 1) % n != a[s[2][i]])){
				return false;
			}
		}
	}
	if(x != 0){
		if(y <= 1){
			if(a[s[y][x]] == -1){
				for(int i = n - 1;i >= 0;i--){
					if(v[i] == false){
						a[s[y][x]] = i;
						v[i] = true;
						bool ret = dfs(x, y + 1, asd);
						if(ret)return true;
						v[i] = false;
						a[s[y][x]] = -1;
					}
				}
				return false;
			}
			else{
				bool ret = dfs(x, y + 1, asd);
				if(ret)return true;
			}
		}
		else{
			if(a[s[y][x]] == -1){
				for(int i = n - 1;i >= 0;i--){
					if(v[i] == false){
						if((a[s[0][x]] + a[s[1][x]] + asd) % n != i){
							continue;
						}
						a[s[y][x]] = i;
						v[i] = true;
						bool ret = dfs(x - 1, 0, (a[s[0][x]] + a[s[1][x]] + asd) / n);
						if(ret)return true;
						v[i] = false;
						a[s[y][x]] = -1;
					}
				}
				return false;
			}
			else{
				if((a[s[0][x]] + a[s[1][x]] + asd) % n != a[s[2][x]]){
					return false;
				}
				bool ret = dfs(x - 1, 0, (a[s[0][x]] + a[s[1][x]] + asd) / n);
				if(ret)return true;
			}
		}
	}
	else{
		if(y <= 1){
			if(a[s[y][x]] == -1){
				for(int i = n - 1;i >= 0;i--){
					if(v[i] == false){
						a[s[y][x]] = i;
						v[i] = true;
						bool ret = dfs(x, y + 1, asd);
						if(ret)return true;
						v[i] = false;
						a[s[y][x]] = -1;
					}
				}
				return false;
			}
			else{
				bool ret = dfs(x, y + 1, asd);
				if(ret)return true;
			}
		}
		else{
			if(a[s[y][x]] == -1){
				for(int i = n - 1;i >= 0;i--){
					if(v[i] == false){
						if((a[s[0][x]] + a[s[1][x]] + asd) % n != i){
							continue;
						}
						if((a[s[0][x]] + a[s[1][x]] + asd) >= n){
							continue;
						}
						a[s[y][x]] = i;
						v[i] = true;
						bool ret = dfs(x - 1, 0, (a[s[0][x]] + a[s[1][x]] + asd) / n);
						if(ret)return true;
						v[i] = false;
						a[s[y][x]] = -1;
					}
				}
				return false;
			}
			else{
				if((a[s[0][x]] + a[s[1][x]] + asd) % n != a[s[2][x]]){
					return false;
				}
				if((a[s[0][x]] + a[s[1][x]] + asd) >= n){
					return false;
				}
				bool ret = dfs(x - 1, 0, (a[s[0][x]] + a[s[1][x]] + asd) / n);
				if(ret)return true;
			}
		}
	}
	return false;
}

void sol(){
	cin>>n;
	
	rep(i, 3){
		cin>>s[i];
		rep(j,n){
			s[i][j] -= 'A';
		}
	}
	rep(i,30)a[i] = -1;
	dfs(n - 1, 0, 0);

}

int main(){
	tt = 1;
	for(ttt = 1;ttt <= tt;ttt++){
		sol();
	}
	system("pause");
	return 0;
}