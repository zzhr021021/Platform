#include<bits/stdc++.h>
using namespace std;

//Luogu P4513
int n, m;
int park[500005];
int segtreesum[2000005];
int segtreemax[2000005];
int segtreemaxl[2000005];
int segtreemaxr[2000005];
void buildtree(int o, int l, int r){
	//cout << o << endl;
	//cout  << "lllllrrrrr" << l << "  " << r  << "  " << o << endl;
	if(l == r){
		segtreesum[o] = park[l];
		segtreemax[o] = park[l];
		segtreemaxl[o] = park[l];
		segtreemaxr[o] = park[l];
		return;
	}
	int mid = (l + r) / 2;
	buildtree(o * 2, l, mid);
	buildtree(o * 2 + 1, mid + 1, r);
	//segtree[o] = segtree[o * 2] + segtree[o * 2 + 1];
	segtreesum[o] = segtreesum[o * 2] + segtreesum[o * 2 + 1];
	if(segtreemaxr[o * 2] < 0 && segtreemaxl[o * 2 + 1] < 0){
		segtreemax[o] = max(segtreemaxr[o * 2], segtreemaxl[o * 2 + 1]);
	}
	else{
		segtreemax[o] = 0;
		segtreemax[o] += max(segtreemaxr[o * 2], 0);
		segtreemax[o] += max(segtreemaxl[o * 2 + 1], 0);
	}
	segtreemax[o] = max(segtreemax[o], segtreemax[o * 2]);
	segtreemax[o] = max(segtreemax[o], segtreemax[o * 2 + 1]);
	segtreemaxl[o] = max(segtreemaxl[o * 2], segtreesum[o * 2] + segtreemaxl[o * 2 + 1]);
	segtreemaxr[o] = max(segtreemaxr[o * 2 + 1], segtreesum[o * 2 + 1] + segtreemaxr[o * 2]);
	return;
}

void singlechange(int o, int loc, int to, int l, int r){
	if(l == r){
		segtreesum[o] = to;
		segtreemax[o] = to;
		segtreemaxl[o] = to;
		segtreemaxr[o] = to;
		return;
	}
	int mid = (l + r) / 2;
	if(loc <= mid){
		singlechange(o * 2, loc, to, l, mid);
	}
	else{
		singlechange(o * 2 + 1, loc, to, mid + 1, r);
	}
	//segtree[o] = segtree[o * 2] + segtree[o * 2 + 1];
	segtreesum[o] = segtreesum[o * 2] + segtreesum[o * 2 + 1];
	if(segtreemaxr[o * 2] < 0 && segtreemaxl[o * 2 + 1] < 0){
		segtreemax[o] = max(segtreemaxr[o * 2], segtreemaxl[o * 2 + 1]);
	}
	else{
		segtreemax[o] = 0;
		segtreemax[o] += max(segtreemaxr[o * 2], 0);
		segtreemax[o] += max(segtreemaxl[o * 2 + 1], 0);
	}
	segtreemax[o] = max(segtreemax[o], segtreemax[o * 2]);
	segtreemax[o] = max(segtreemax[o], segtreemax[o * 2 + 1]);
	segtreemaxl[o] = max(segtreemaxl[o * 2], segtreesum[o * 2] + segtreemaxl[o * 2 + 1]);
	segtreemaxr[o] = max(segtreemaxr[o * 2 + 1], segtreesum[o * 2 + 1] + segtreemaxr[o * 2]);
	return;
}

int query(int o, int l, int r, int L, int R){
	if(L <= l && R >= r)return segtreesum[o];
	int mid = (l + r) / 2;
	if(L <= mid && mid < R){
		
		return segtreemax[o];
	}
	else if(L <= mid){
		return query(o * 2, l, mid, L, R);
	}
	else{
		return query(o * 2, mid + 1, r, L, R);
	}
	
	//return r1 + r2;
}
int main(){
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> park[i];
	}
	buildtree(1, 1, n);
	for(int i = 0;i < 4 * n;i++){
		cout << "i = " << i << " seg[i] = " << segtreesum[i] << endl;
	}
	for(int i = 0;i < m;i++){
		int mode, a, b;
		cin >> mode >> a >> b;
		if(mode == 1){
			if(a > b){
				int temp = a;
				a = b;
				b = temp;
				
			}
			cout << query(1, 1, n, a, b) << endl;
		}
		else{
			singlechange(1, a, b, 1, n);
		}
	}
	return 0;
}

//5 3
//1
//2
//-3
//4
//5
//1 2 3
//2 2 -1
//1 2 3
