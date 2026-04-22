#include <iostream>

using ll = long long;
using namespace std;
int n;
ll dp[1000010];
int main()
{
	dp[0] = 1;
	for (int i = 0; i <= 1000; i++) {
		dp[i + 1] += dp[i];
		dp[i + 2] += dp[i];
	}
	while (1) {
		int a;
		cin >> a;
		if (a == 0) {
			break;
		}
		cout << dp[a] << '\n';
	}
}