#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Read all integers from stdin
    vector<long long> all;
    long long x;
    while ( (cin >> x) ) all.push_back(x);
    if (all.empty()) return 0;

    vector<long long> h;
    // If first number equals count of following numbers, treat it as n
    if (all.size() >= 2 && all[0] == (long long)all.size() - 1) {
        h.assign(all.begin() + 1, all.end());
    } else {
        // Otherwise treat entire input as heights array
        h = all;
    }

    int n = (int)h.size();
    if (n <= 2) {
        cout << 0 << '\n';
        return 0;
    }

    int l = 0, r = n - 1;
    long long leftMax = 0, rightMax = 0;
    long long ans = 0;
    while (l <= r) {
        if (h[l] <= h[r]) {
            if (h[l] >= leftMax) leftMax = h[l];
            else ans += leftMax - h[l];
            ++l;
        } else {
            if (h[r] >= rightMax) rightMax = h[r];
            else ans += rightMax - h[r];
            --r;
        }
    }

    cout << ans << '\n';
    return 0;
}