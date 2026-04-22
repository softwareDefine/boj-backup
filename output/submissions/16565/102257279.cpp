#define mod 10007
#include <bits/stdc++.h>

using namespace std;

int n;
int dp[100][100];

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
    cout << ((c(13,n/4) % mod) * (c(52-(n/4)*4,n%4) % mod))%mod;
    return 0;
}