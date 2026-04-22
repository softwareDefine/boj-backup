#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n;
ll arr[10010], brr[10010];

ll dp[3005][3005];

ll go(int i, int j) {
    if (i == n || j == n) return 0;
    ll &ret = dp[i][j];
    if (ret != -1) return ret;

    ret = max(go(i + 1, j), go(i + 1, j + 1));
    if (arr[i] > brr[j]) ret = max(ret, go(i, j + 1) + brr[j]);
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i) cin >> arr[i];
    for (int i = 0; i < n; ++i) cin >> brr[i];

    memset(dp, -1, sizeof(dp));

    cout << go(0, 0);
    return 0;
}
