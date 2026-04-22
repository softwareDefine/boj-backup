#include <iostream>
#include <string>

using namespace std;

int n, m;
int dp[1010][1010];
int mmx;
string arr[1010];
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		for (int j = 0; j < arr[i].length(); j++) {
			if (arr[i][j] == '0') {
				dp[i][j+1] = 0;
			}
			else {
				dp[i][j+1] = 1;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (dp[i][j] == 0) {
				dp[i][j] = 0;
			}
			else {
				dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			mmx = max(dp[i][j], mmx);
		}
	}
	cout << mmx*mmx;
}
