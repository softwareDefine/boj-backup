#include <iostream>
#define inf 9999999999


 using ll = long long;
using namespace std;
ll dp[100010][110];
int n, m;

ll go(int n, int m) {
	if (n < m) { swap(n, m); }
	if (dp[n][m]) { return dp[n][m]; }
	dp[n][m] = inf;
	if (n % m == 0) {
		return dp[n][m] = n / m;
	}
	if (n >= 10 * m) {
		return dp[n][m] = min(dp[n][m], go(n - m,m) + 1);
	}
	ll ans = inf;
	for (int i = 1; i < n; i++) {
		ans = min(ans, go(n - i, m) + go(i, m));
	}
	for (int i = 1; i < m; i++) {
		ans = min(ans, go(n, m - i) + go(n, i));
	}
	return dp[n][m] = ans;
}

int main()
{
	cin >> n >> m;
	cout << go(n, m);
}