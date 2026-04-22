#define mod 10007
#include <bits/stdc++.h>

using namespace std;

int n;
int dp[100][100];
int ans = 0;
int res = 1;

int c(int i, int j){
    if(dp[i][j]){ return dp[i][j]; }
    if(j == 0 || i == j){
        return dp[i][j] = 1;
    }
    return dp[i][j] = (c(i-1,j-1)%mod + c(i-1,j)%mod)%mod;
}

int main() {
    cin >> n;
    if( n < 4){
        cout << 0;
        return 0;
    }
    for(int i = 1; n - i*4 >= 0; i++){
        ans =(ans%mod + ((c(13,i)%mod)*(c(52 - i*4, n - i*4)%mod)*res %mod + mod)%mod)%mod;
        res = res*(-1);
    }
    cout << ans;
    return 0;
}