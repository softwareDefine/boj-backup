#include <iostream>

using ll = long long;
using namespace std;

int n;
ll arr[51];
// i번째 블록까지 봤고 j만큼 차이가 있을때
// 항상 0보다 크거나 같은것이 자명함
// 따라서 왼쪽 타워가 크다고 가정하면????
ll dp[51][500010];
ll mmx;

int main()
{
	for (int i = 0; i < 51; i++) {
		for (int j = 0; j < 500010; j++) {
			dp[i][j] = -1;
		}
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	dp[0][0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 500010; j++) {
			if (dp[i][j] != -1) {
				// arr[i]가 앞에 추가된 경우
				//dp[i][j]+j, dp[i][j]
				//[dp[i][j] + j + arr[i] - dp[i][j]];
				dp[i + 1][j + arr[i]] = max(dp[i][j], dp[i + 1][j + arr[i]]);
				// arr[i]가 뒤에 추가된 경우
				//dp[i][j]+j, dp[i][j]+arr[i]
				if (j < arr[i]) {
					dp[i + 1][arr[i] - j] = max(j + dp[i][j], dp[i + 1][arr[i] - j]);
				}
				else {
					// 앞에가 더 적은 상황이었는데 뒤에가 더 커졌음
					// dp[i][j] + j , dp[i][j] + arr[i]
					dp[i + 1][j - arr[i]] = max(arr[i] + dp[i][j], dp[i + 1][j - arr[i]]);
				}
				dp[i + 1][j] = max(dp[i][j], dp[i + 1][j]);
				//cout << i << ' ' << j << ' ' << dp[i][j] << '\n';
			}
		}
		mmx = max(dp[i][0], mmx);
	}
	if (dp[n][0] == 0) {
		cout << -1;
	}
	else {
		cout << dp[n][0];
	}
}