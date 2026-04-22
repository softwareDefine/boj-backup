#include <iostream>
using namespace std;

int main() {
    int n, dp[1001];
    cin >> n;
    dp[0] = 1;
    dp[2] = 3;
    dp[4] = 11;
    for (int i = 6; i <= n; i += 2) {
        dp[i] = dp[i-2]*dp[2];
        for(int j=i-4;j>=0;j-=2){
            dp[i] += dp[j]*2;
        }
    }
    cout << dp[n];
    return 0;
}