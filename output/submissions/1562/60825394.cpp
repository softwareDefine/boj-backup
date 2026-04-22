#include <iostream>
#define mod 1000000000

using ll = long long;
using namespace std;
ll dp[101][10][1024];
ll sum;
int n;
int main()
{
	cin >> n;
	dp[0][1][1 << 1] = 1;
	dp[0][2][1 << 2] = 1;
	dp[0][3][1 << 3] = 1;
	dp[0][4][1 << 4] = 1;
	dp[0][5][1 << 5] = 1;
	dp[0][6][1 << 6] = 1;
	dp[0][7][1 << 7] = 1;
	dp[0][8][1 << 8] = 1;
	dp[0][9][1<<9] = 1;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = 0; k <= 1023; k++) {
				ll first = (j!=0)?dp[i - 1][j - 1][k]:0;
				ll second = (j!=9)?dp[i - 1][j + 1][k]:0;
				dp[i][j][k | (1 << j)] = ((dp[i][j][k | (1 << j)]%mod + first%mod)%mod + second%mod)%mod;
			}
		}
	}
	for (int i = 0; i <= 9; i++) {
		sum = (dp[n-1][i][1023] + sum)%mod;
	}
	cout << sum;
}