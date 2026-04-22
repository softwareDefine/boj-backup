#include <iostream>

using namespace std;
int dp[10100];
int n,m;
int main()
{
    cin >> n;
    //1 선공 2 후공
    dp[0] = 1;
    dp[1] = 2;
    dp[2] = 1;
    dp[3] = 2;
    for (int i = 4; i <=n; i++) {
        if (dp[i - 1] == 1 && dp[i - 3] == 1 && dp[i - 4] == 1) {
            dp[i] = 2;
        }
        else {
            dp[i] = 1;
        }
    }
    if (dp[n]==1) {
        cout << "SK";
    }
    else if(dp[n]==2) {
        cout << "CY";
    }
}