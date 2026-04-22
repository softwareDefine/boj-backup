#define mod 1000000000
#include <bits/stdc++.h>

//using lint = long long;
using namespace std;

int n, k;
int dp[5100][5100];

int go(int i, int j){
    if(dp[i][j] != -1){ return dp[i][j]; }
    if(i == j || j == 0){
        return 1;
    }
    return dp[i][j] = ((go(i-1, j)%mod) + (go(i-1, j-1)%mod))%mod;
}

int main() {
    memset(dp, -1, sizeof(dp));
	cin >> n >> k;
	cout << go(k+n-1, k-1);
	return 0;
}