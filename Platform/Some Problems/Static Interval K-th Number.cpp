#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)

using i32 = int;
using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

#define csp(n) cout << n << " "
#define cend(n) cout << n << endl
#define cendl cout << endl
#define ctest cout << "test   "

const i64 inf = 1e18;
const i64 N = 200005;
using namespace std;

i64 tt, ttt;
i64 n,k,m,t,x,y,z;
i64 a[N];
struct qu{
	i64 op, x, y, z;
}qus[N << 1], qul[N << 1], qur[N << 1];
i64 ans[N << 1];

struct BIT {
    int tr[N];
    #define lowbit(x) (x&-x)
    void add(int x , int y) { for (; x <= n; x += lowbit(x)) tr[x] += y; }
    int _query(int x) {
        int res = 0;
        for (; x; x -= lowbit(x)) res += tr[x];
        return res;
    }
    int query(int l , int r) {
        return _query(r) - _query(l - 1);
    }
} bit;

void solve(i64 l, i64 r, i64 whl, i64 whr){
	if(whl > whr)return;
	if(l == r){
		for(int i = whl;i <= whr;i++){
			auto o = qus[i];
			ans[o.op] = l;
		}
		return;
	}
	i64 cntl = 0, cntr = 0;
	i64 mid = (l + r) / 2;
	for(int i = whl;i <= whr;i++){
		if(qus[i].op == 0){
			if(qus[i].y <= mid){
				bit.add(qus[i].x + 1, 1);
				qul[cntl] = qus[i];
				cntl++;
			}
			else{
				qur[cntr] = qus[i];
				cntr++;
			}
		}
		else{
			i64 cnt = bit.query(qus[i].x + 1, qus[i].y + 1);
			if(cnt >= qus[i].z){
				qul[cntl] = qus[i];
				cntl++;
			}
			else{
				qus[i].z -= cnt;
				qur[cntr] = qus[i];
				cntr++;
			}
		}
	}
	for(int i = 0;i < cntl;i++){
		if(qul[i].op == 0)bit.add(qul[i].x + 1, -1);
	}
	for(int i = 0;i < cntl;i++){
		qus[whl + i] = qul[i];
	}
	for(int i = 0;i < cntr;i++){
		qus[whl + i + cntl] = qur[i];
	}
	solve(l, mid, whl, whl + cntl - 1);
	solve(mid + 1, r, whl + cntl, whr);
}

void sol(){
	cin>>n>>m;

	rep(i,n){
		cin>>a[i];
		qus[i].op = 0;
		qus[i].x = i;
		qus[i].y = a[i];
	}
	rep(j,m){
		i64 i = j + n;
		cin>>qus[i].x>>qus[i].y>>qus[i].z;
		qus[i].op = j;qus[i].x--;qus[i].y--;
		qus[i].op++;
	}
	i64 u = 2e9;
	i64 d = -1;

	solve(d, u, 0, n + m - 1);

	rep1n(i,m)cend(ans[i]);
}

int main(){
	ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
	sol();
	system("pause");
	return 0;
}
