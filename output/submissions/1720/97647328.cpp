#include <iostream>
using namespace std;

int dp[1010];
int n;

int main() {
    cin >> n;
    dp[1] = 1;
    dp[2] = 3;
    dp[3] = 5;
    for (int i = 4; i <= n; i++) {
        dp[i] = dp[i - 1] + 2 * dp[i - 2];
    }
    if(n >= 3){
        if(n%2 == 0){
            dp[n]=dp[n]+dp[n/2]+dp[(n-2)/2]*2;
        }else{
            dp[n]=dp[n]+dp[n/2];
        }
        cout << dp[n]/2;
    }else{
        cout << dp[n];
    }
}
