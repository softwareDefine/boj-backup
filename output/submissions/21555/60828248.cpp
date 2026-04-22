#include <iostream>

using ll = long long;
using namespace std;

int n ,k;
ll dp[200010][2];
ll arr[200010][2];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i][0];
	}
	for (int i = 0; i < n; i++) {
		cin >> arr[i][1];
	}
	dp[0][0] = arr[0][0];
	dp[0][1] = arr[0][1];
	for (int i = 1; i < n; i++) {
		dp[i][0] = min(dp[i - 1][0] + arr[i][0], dp[i - 1][1] + arr[i][0] + k);
		dp[i][1] = min(dp[i - 1][1] + arr[i][1], dp[i - 1][0] + arr[i][1] + k);
	}
	cout << min(dp[n - 1][0], dp[n - 1][1]);
}