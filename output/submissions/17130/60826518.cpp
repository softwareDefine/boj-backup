#include <iostream>
#include <string>

using namespace std;
int x,y;
string arr[1010];
int dp[1010][1010];
pair<int, int> rabbit;
int mmny;
int mmxy;
int ans = -1;
int main()
{
	cin >> x >> y;
	for (int i = 0; i < 1010; i++) {
		for (int j = 0; j < 1010; j++) {
			dp[i][j] = -1;
		}
	}
	for (int i = 0; i < x; i++) {
		cin >> arr[i];
		for (int j = 0; j < y; j++) {
			if (arr[i][j] == 'R') {
				rabbit = { i,j };
			}
		}
	}
	//x좌표 // y좌표
	dp[rabbit.first][rabbit.second] = 0;
	for (int j = rabbit.second + 1; j < y; j++) {
		for (int i = 0; i < x; i++) {
			if (arr[i][j] == 'C') {
				if (i - 1 >= 0 && dp[i-1][j-1]>=0) {
					dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);
				}
				if (i + 1 < x && dp[i+1][j - 1] >= 0) {
					dp[i][j] = max(dp[i][j], dp[i+1][j-1]+1);
				}
				if (dp[i][j - 1] >= 0) {
					dp[i][j] = max(dp[i][j], dp[i][j - 1]+1);
				}
			}
			else if (arr[i][j] == '#') {
			}
			else {
				if (i - 1 >= 0 && dp[i - 1][j - 1] >= 0) {
					dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
				}
				if (i + 1 < x && dp[i + 1][j - 1] >= 0) {
					dp[i][j] = max(dp[i][j], dp[i + 1][j - 1]);
				}
				if (dp[i][j - 1] >= 0) {
					dp[i][j] = max(dp[i][j], dp[i][j - 1]);
				}
			}
		}
	}
	for (int i = 0; i < x; i++){
		for (int j = 0; j < y; j++) {
			if (arr[i][j] == 'O') {
				ans = max(dp[i][j], ans);
			}
		}
	}
	cout << ans;
}
