/*
 * @Author: chhokmah 
 * @Date: 2020-03-22 16:20:53 
 * @Last Modified by:   chhokmah 
 * @Last Modified time: 2020-03-22 16:20:53 
 */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 5;

struct Node {
  int i, l, r;

  Node() { 
    i = l = r = 0;
  }

  Node(int x, int y, int z) {
    i = x, l = y, r = z;
  }
} q[N];

char s[N][35];
int n, L, P;
int a[N], g[N];
long double sum[N], f[N];

int main() {
//   ios::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
  int t;
  cin >> t;
  auto pw = [](long double x, int y) {
    long double res = 1;
    while (y) {
      if (y & 1) {
        res = res * x;
      }
      y >>= 1, x *= x;
    }
    return res;
  };
  while (t--) {
    cin >> n >> L >> P;
    for (int i = 1; i <= n; i++) {
      cin >> s[i];
      a[i] = strlen(s[i]);
    }
    for (int i = 1; i <= n; i++) {
      sum[i] = sum[i - 1] + a[i];
    }
    auto calc = [&](int l, int r) {
      return f[l] + pw(fabs(sum[r] - sum[l] + r - l - 1 - L), P);
    };
    int head = 1, tail = 1;
    q[tail] = Node(0, 1, n);
    for (int i = 1; i <= n; i++) {
      while (head < tail && q[head].r < i) {
        head++;
      }
      f[i] = calc(g[i] = q[head].i, i);
	  cout << "test " << i << " " << f[i] << endl;
      while (head <= tail && calc(q[tail].i, q[tail].l) >= calc(i, q[tail].l)) {
        tail--;
      }
      if (head > tail) {
        q[++tail] = Node(i, i + 1, n);
      } else {
        int lw = q[tail].l, hg = q[tail].r, res = q[tail].r + 1;
        while (lw <= hg) {
          int mid = (lw + hg) >> 1;
          if (calc(q[tail].i, mid) < calc(i, mid)) {
            lw = mid + 1;
          } else {
            res = mid;
            hg = mid - 1;
          }
        }
        q[tail].r = res - 1;
        if (res <= n) {
          q[++tail] = Node(i, res, n);
        }
      }
    }
    if (f[n] > 1e18) {
      cout << "Too hard to arrange" << '\n';
    } else {
      cout << (long long)f[n] << '\n';
      vector<int> pt; 
      pt.clear();
      int it = n;
      while (it) {
        pt.emplace_back(it);
        it = g[it];
      }
      pt.emplace_back(0);
      reverse(pt.begin(), pt.end());
      for (int i = 0; i < (int)pt.size() - 1; i++) {
        for (int j = pt[i] + 1; j <= pt[i + 1]; j++) {
          cout << s[j] << " \n"[j == pt[i + 1]];
        }
      }
    }
    cout << "--------------------";
    if (t != 0) {
      cout << '\n';
    }
  }
  return 0; 
}