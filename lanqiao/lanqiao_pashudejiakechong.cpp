#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int a[N], dp[N];
int leftlen[N];
int rightlen[N];

int n, k;
int LIS(int L, int R) //???LIS
{
    int len = 0;
    dp[len] = -0x3f3f3f3f;
    for (int i = L; i <= R; i++)
    {
        if (a[i] >= dp[len])
        {
            ++len;
            dp[len] = a[i];

            leftlen[i] = len;
        }
        else{
          int p = upper_bound(dp + 1, dp + 1 + len, a[i]) - dp;
          dp[p] = a[i];
          leftlen[i] = p;
        }

    }
    return len;
}

int LIS2(int L, int R) //???LIS
{
    int len = 0;
    dp[len] = -0x3f3f3f3f;
    for (int i = R; i >= L; i--)
    {
        if (a[i] >= dp[len])
        {
            ++len;
            dp[len] = a[i];

            rightlen[i] = len;
        }
        else{
          int p = upper_bound(dp + 1, dp + 1 + len, a[i]) - dp;
          dp[p] = a[i];
          rightlen[i] = p;
        }

    }
    return len;
}
void solve()
{
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    if (n - 1 <= k)
    //??k????????
    {
        printf("%d\n", n);
        return;
    }
    int ans = k + 1;
    int temp  = LIS(1, n);;
    for(int i = 1;i <= n;i++){
      cout << leftlen[i] << "  ";
    }
    for(int i = 1;i <= n;i++){
    	a[i] = 1000000000 - a[i];
	}
    temp  = LIS2(1, n);;
    for(int i = 1;i <= n;i++){
      cout << rightlen[i] << "  ";
    }
}

int main()
{
    solve();
    return 0;
}


