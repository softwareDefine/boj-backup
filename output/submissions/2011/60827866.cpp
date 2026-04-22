#include <iostream>

using namespace std;

string str;
int dp[5100];
int flag;
int main()
{
	cin >> str;
	dp[0] = 1;
	if (str.length() == 1 && str[0] == '0') {

	}
	else {
		for (int i = 0; i < str.length(); i++) {
			if (i != str.length() - 1) {
				int k = (str[i] - '0') * 10 + (str[i + 1] - '0');
				if (k >= 10 && k <= 26) {
					dp[i + 2] = (dp[i] + dp[i + 2] + 1000000) % 1000000;
				}
				if (str[i] == '0' && str[i + 1] == '0') {
					dp[str.length()] = 0;
					break;
				}
			}
			if (str[i] != '0') {
				dp[i + 1] = (dp[i] + dp[i + 1] + 1000000) % 1000000;
			}
		}
	}
	cout << dp[str.length()];
}