#include <iostream>

using namespace std;

int dp[1010][1010];
string str, ptr;

int main()
{
	cin >> str;
	cin >> ptr;
	for (int i = 1;i <= str.size();i++) {
		for (int j = 1;j <= ptr.size();j++) {
			if (str[i-1] == ptr[j-1]) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	cout << str.size()+ptr.size()-dp[str.size()][ptr.size()];
}