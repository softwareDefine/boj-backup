#include <iostream>

using namespace std;

int arr[5000];
int arr2[5000];
int dp[5010][5010];
int n;

int main()
{
	cin >> n;
	for (int i = 1;i <= n;i++) {
		cin >> arr[i];
	}
	for (int i = 1;i <= n;i++) {
		arr2[n - i + 1] = arr[i];
	}
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			if (arr[i] == arr2[j]) {
				dp[i][j] = max(dp[i - 1][j - 1] + 1, dp[i][j]);
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	cout << n-dp[n][n];
}