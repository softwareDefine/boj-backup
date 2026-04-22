#include <iostream>
#define mod 1000000000

using namespace std;

int n;

long long dp[100010][10];

int main()
{
    cin >> n;
    dp[0][1] = 1;
    dp[0][2] = 1;
    dp[0][3] = 1;
    dp[0][4] = 1;
    dp[0][5] = 1;
    dp[0][6] = 1;
    dp[0][7] = 1;
    dp[0][8] = 1;
    dp[0][9] = 1;
    for (int i = 1; i < n; i++) {
        dp[i][0] = dp[i-1][1]%mod;
        for (int j = 1;j<9; j++) {
            dp[i][j] = (dp[i - 1][j-1]%mod + dp[i - 1][j+1]%mod)%mod;
        }
        dp[i][9] = dp[i - 1][8]%mod;
    }
    long long sum=0;
    for (int j = 0; j <= 9; j++) {
       sum = (dp[n - 1][j]%mod+sum%mod)%mod;
    }
    cout << sum%mod;
}