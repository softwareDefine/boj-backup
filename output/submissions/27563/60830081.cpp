#include <iostream>

using ll = long long;
using namespace std;

int t;
int dp[110];
int cnt = 999;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	cin >> t;
	while (t--) {
		for (int i = 0; i < 110; i++) {
			dp[i] = 0;
		}
		cnt = 999;
		string str;
		cin >> str;
		if (str.size() == 1 || str.size() == 2) {
			cout << "-1" << '\n';
			continue;
		}
		for (int i = 0; i < str.size() - 2; i++) {
			if (str[i] != 'M') {
				dp[i]++;
			}
			if (str[i + 2] != 'O') {
				dp[i]++;
			}
			if (str[i + 1] != 'O') {
				dp[i] = -1;
			}
		}
		for (int i = 0; i < str.size() - 2; i++) {
			if (dp[i] == -1) {
				continue;
			}
			cnt = min(dp[i] + int(str.size()-3), cnt);
		}
		if (cnt == 999) {
			cout << "-1" << '\n';
		}
		else {
			cout << cnt << '\n';
		}
	}
}