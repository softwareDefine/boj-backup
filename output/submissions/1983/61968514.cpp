#include <iostream>
#include <vector>

using ll = long long;
using namespace std;

int n, first, second;
vector<int> arr, brr;
int mmx = -99999999999;
int dp[410][410][410];
bool visited[410][410][410];

int main()
{
	for (int i = 0; i < 410; i++) {
		for (int j = 0; j < 410; j++) {
			for (int k = 0; k < 410; k++) {
				dp[i][j][k] = -999999999;
			}
		}
	}
	cin >> n;
	for (int i = 1; i <= n; i++) {
		ll a; cin >> a;
		if (a)	arr.push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		ll a; cin >> a;
		if (a)	brr.push_back(a);
	}
	while (n - arr.size()) {
		arr.push_back(0);
		first++;
	}
	while (n - brr.size()) {
		brr.push_back(0);
		second++;
	}
	dp[0][0][0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			for (int k = 0; k <= i; k++) {
				if (i + 1 - j <= first && i + 1 - k <= second) {
					if (!visited[j][k][i + 1]) {
						dp[j][k][i + 1] = dp[j][k][i];
						visited[j][k][i + 1] = 1;
					}else{
						dp[j][k][i + 1] = max(dp[j][k][i], dp[j][k][i + 1]);
					}
				}
				if (i + 1 - k <= second) {
					if (!visited[j + 1][k][i + 1]) {
						dp[j + 1][k][i + 1] = dp[j][k][i];
						visited[j + 1][k][i + 1] = 1;
					}
					else {
						dp[j + 1][k][i + 1] = max(dp[j][k][i], dp[j + 1][k][i + 1]);
					}
				}
				if (i + 1 - j <= first) {
					if (!visited[j][k+1][i + 1]) {
						dp[j][k+1][i + 1] = dp[j][k][i];
						visited[j][k+1][i + 1] = 1;
					}
					else {
						dp[j][k + 1][i + 1] = max(dp[j][k][i], dp[j][k + 1][i + 1]);
					}
				}
				if (!visited[j + 1][k + 1][i + 1]) {
					dp[j+1][k + 1][i + 1] = dp[j][k][i] + arr[j] * brr[k];
					visited[j+1][k + 1][i + 1] = 1;
				}
				else {
					dp[j + 1][k + 1][i + 1] = max(dp[j][k][i] + arr[j] * brr[k], dp[j + 1][k + 1][i + 1]);
				}
			}
		}
	}
	for (int j = 0; j <= n; j++) {
		for (int k = 0; k <= n; k++) {
			mmx = max(dp[j][k][n], mmx);
			//cout << dp[j][k][n] << '\n';
		}
	}
	cout << mmx;
}