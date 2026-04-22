#include <iostream>

using namespace std;

int n;
int arr[510][510];
int dp[510][510];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            cin >> arr[i-1][j];
        }
    }
    dp[0][0] = arr[0][0];
    dp[1][0] = arr[0][0]+arr[1][0];
    dp[1][1] = arr[0][0]+arr[1][1];
    for (int i = 3; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (j == 0) {
                dp[i - 1][0] = dp[i - 2][0] + arr[i - 1][0];
            }
            else if (j == i-1)
            {
                dp[i - 1][j] = dp[i - 2][i-2] + arr[i - 1][i-1];
            }
            else {
                dp[i - 1][j] = max(dp[i - 2][j], dp[i - 2][j - 1]) + arr[i - 1][j];
            }
        }
    }
    int mmx= dp[n-1][0];
    for (int i = 0; i < n; i++) {
        mmx = max(mmx, dp[n - 1][i]);
    }
    cout << mmx;
}