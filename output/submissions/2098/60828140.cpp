#include <iostream>
//자력솔 도전!

using namespace std;

int n;

//i에서 j까지 갔고 지금까지 거친 정점들 즉 K에서 온 최단거리
//dp[i][j][k]
unsigned int dp[16][16][65536];
unsigned int w[16][16];
unsigned int mmn = 999999999;


int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < (1 << n); k++) {
				dp[i][j][k] = 99999999;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		dp[i][i][0] = 0;
		dp[i][i][(1 << i)] = 0;
		for (int j = 0; j < n; j++) {
			cin >> w[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int k= 0; k < (1<<n); k++) {
			for (int j = 0; j < n; j++) {
				if ((k & (1 << j)) == 0) {
					for (int s = 0; s < n; s++) {
						if (w[s][j] == 0) { continue; }
						dp[i][j][k | (1 << j)] = min(dp[i][j][k | (1 << j)], dp[i][s][k] + w[s][j]);
					}
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		mmn = min(mmn, dp[i][i][(1 << n) - 1]);
		//cout << dp[i][i][(1 << n) - 1] << '\n';
	}
	cout << mmn;
}