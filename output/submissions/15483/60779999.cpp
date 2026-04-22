#include <iostream>

using namespace std;

int dp[1010][1010];
string ptr, str;

int main()
{
	cin >> ptr;
	cin >> str;
	for (int i = 1; i <= max(str.size(), ptr.size()); i++) {
		dp[i][0] = i;
		dp[0][i] = i;
	}
	for (int i = 1; i <= ptr.size(); i++) {
		for (int j = 1; j <= str.size(); j++) {
			if (ptr[i - 1] == str[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1];
			}
			else {
				dp[i][j] = min(dp[i-1][j-1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
			}
		}
	}
	cout << dp[ptr.size()][str.size()];
}