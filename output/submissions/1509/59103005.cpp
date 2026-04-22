#include <iostream>

using namespace std;

string str;
bool chk[2510][2510];
int dp[2510];
int szze;

void init() {
	for (int d = 0; d < szze; d++) {
		for (int j = 1; j+d<=szze; j++) {
			if (d == 0) {
				chk[j][j] = true;
				continue;
			}
			if ((d == 1 || chk[j+1][j + d-1]) && str[j+d] == str[j]) {
				chk[j][j+d] = true;
			}
		}
	}
}

int main()
{
	cin >> str;
	szze = str.size();
	str = " " + str;
	init();
	for (int i = 1; i <= str.length(); i++) {
		dp[i] = 10000000;
	}
	dp[0] = 0;
	for (int i = 1; i < str.length(); i++) {
		for (int j = 1; j <= i; j++) {
			if (chk[j][i]) {
				dp[i] = min(dp[j-1] + 1, dp[i]);
			}
		}
	}
	cout << dp[szze];
}