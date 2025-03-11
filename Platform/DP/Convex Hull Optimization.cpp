// Luogu P5785
// convex hull optimization
#include <cstdio>
#include <iostream>
typedef long long ll;
const int N = 3e5 + 5 ;
int l = 1 , r = 0 ;
ll sc[N], st[N], f[N], n, s, q[N];
ll Y(int p) {return f[p];}
ll X(int p) {return sc[p];}
ll K(int p) {return s + st[p];}
int Search(int L, int R, long long S) {
	int M = 0 , Res = r ;
	while(L <= R) {
		M = ( L + R ) >> 1; 
		if(Y(q[M + 1]) - Y(q[M]) > S * (X(q[M + 1]) - X(q[M]))) // 由所得性质二分
			R = M - 1, Res = M;
		else L = M + 1; // 二分+-1防止死循环
	}
	return q[Res];
} // 二分查找决策点
int main() {
	scanf("%lld %lld", &n, &s);
	for(int i = 1; i <= n; ++i) {
		scanf("%lld %lld", st + i, sc + i);
		st[i] += st[i - 1];
		sc[i] += sc[i - 1];
	} // 前缀和
	q[++ r] = 0 ;// 0 为第一个决策点
	for(int i = 1; i <= n; ++i) {
		int p = Search(l, r, K(i));
		f[i] = f[p] + s * (sc[n] - sc[p]) + st[i] * (sc[i] - sc[p]); // 按照dp方程式更新答案
		while(l < r && (Y(q[r]) - Y(q[r - 1])) * (X(i) - X(q[r])) 
			>= (Y(i) - Y(q[r])) * (X(q[r]) - X(q[r - 1]))) -- r; // 除去上凸点 ， 这里把算斜率的除法转换为乘法以防误差
		q[++ r] = i; // 入队列
	}
	printf("%lld\n", f[n]); // 完美输出
	return 0; // 好习惯
}