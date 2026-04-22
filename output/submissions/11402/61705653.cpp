#include <iostream>
#include <string.h>

using ll = long long;
using namespace std;

ll n, m, k;
ll dp[2100][2100];
ll sum = 1;
// iCj
ll go(int i, int j) {
	if (i < j) return 0;
	if (dp[i][j]!=-1) { return dp[i][j]; }
	if (j == 1) {return dp[i][j] = i;}
	if (j == 0) {  return dp[i][j] = 1; }
	return dp[i][j] = (go(i - 1, j-1)%m + go(i - 1, j)%m)%m;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	memset(dp, -1, sizeof(dp));
	cin >> n >> k >> m;
	while (n || k) {
		sum *=go(n %m, k % m)%m;
		sum %= m;
		n /= m;
		k /= m;
	}
	cout << sum;
}