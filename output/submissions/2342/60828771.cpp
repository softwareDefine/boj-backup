#include <iostream>

using ll = long long;
using namespace std;
int cnt = 0;
ll dp[100010][5][5];
ll arr[100010];
ll mmn = 9999999;
int main()
{
	for (int i = 0; i < 100010; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				dp[i][j][k] = 999999;
			}
		}
	}
	while (1) {
		int a;
		cin >> a;
		if (a == 0) {
			break;
		}
		arr[cnt+1] = a;
		cnt++;
	}
	dp[0][0][0] = 0;
	dp[1][arr[1]][0] = 2;
	dp[1][0][arr[1]] = 2;
	for (int i = 2; i <= cnt; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				int use = 0;
				if (arr[i] == k) {
					use = 1;
				}
				else if ((arr[i] == 2 && (k == 1 || k == 3)) || (arr[i] == 1 && (k == 4 || k == 2)) || (arr[i] == 3 && (k == 2 || k == 4)) || (arr[i] == 4 && (k == 1 || k == 3))) {
					use = 3;
				}
				else if (k == 0) {
					use = 2;
				}
				else {
					use = 4;
				}
				dp[i][j][arr[i]] = min(dp[i][j][arr[i]], dp[i - 1][j][k] + use);
				dp[i][arr[i]][j] = min(dp[i][arr[i]][j], dp[i - 1][k][j] + use);
				mmn = 9999999;
			}
		}
	}
	for (int l = 0; l < 5; l++) {
		for (int m = 0; m < 5; m++) {
			mmn = min(dp[cnt][l][m], mmn);
		}
	}
	cout << mmn;
}