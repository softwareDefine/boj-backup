#include <iostream>

using namespace std;

int n, k;
int arr[100010];
int dp[100010];
int main()
 {
    for (int i = 0; i < 100010; i++) {
        dp[i] = 999999;
    }
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = arr[i]; j <= k; j++) {
            dp[j] = min(dp[j - arr[i]]+1,dp[j]);
        }
    }
    if (dp[k]== 999999) {
        cout << -1;
    }
    else {
    cout << dp[k];
    }
}