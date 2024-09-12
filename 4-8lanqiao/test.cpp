#include<cstdio>
#include<iostream>
using namespace std;

int leftp[100005]; 
int rightp[100005];

bool notprint[100005];
int n, m;
int main(){
	leftp[1] = 1;
	rightp[1] = 1;
	cin >> n;
	int theleft = 1;
	for(int i = 2;i <= n;i++){
		int tar, mode;
		cin >> tar >> mode;
		if(mode){
			if(rightp[tar] == tar){
				rightp[tar] = i;
				rightp[i] = i;
				leftp[i] = tar;
			}
			else{
				leftp[i] = tar;
				rightp[i] = rightp[tar];
				leftp[rightp[tar]] = i;
				rightp[tar] = i;
			}
		}
		else{
			if(leftp[tar] == tar){
				leftp[tar] = i;
				leftp[i] = i;
				rightp[i] = tar;
				theleft = i;
			}
			else{
				rightp[i] = tar;
				leftp[i] = leftp[tar];
				rightp[leftp[tar]] = i;
				leftp[tar] = i;
			}
		}
	}
	
	
	cin >> m;
	for(int i = 0;i < m;i++){
		int dele;
		cin >> dele;
		notprint[dele] = 1;
	}
	
	while(rightp[theleft] != theleft){
		if(!notprint[theleft])cout << theleft << " ";
		theleft = rightp[theleft];
	}
	if(!notprint[theleft])cout << theleft;
	return 0;
}
