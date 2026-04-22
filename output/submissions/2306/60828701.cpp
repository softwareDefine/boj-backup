#include <iostream>

using namespace std;

string str;
int dp[501][501];
int visit[501][501];
int mmx;

int go(int start, int end) {
	if (dp[start][end] || visit[start][end]) {
		return dp[start][end];
	}
	visit[start][end] = 1;
	if ((str[start] == 'a' && str[end] == 't') || (str[start] == 'g' && str[end] == 'c')) {
		dp[start][end] = max(dp[start][end], go(start + 1, end - 1) + 2);
	}
	for (int k = start; k < end; k++) {
		dp[start][end] = max(dp[start][end], go(start,k) + go(k + 1,end));
	}
	return dp[start][end];
}

int main()
{
	cin >> str;
	/*for (int i = 1; i < str.size(); i++) {
		for (int j = 0; j < i; j++) {
			if (str[j] == 'a' && str[i] == 't') {
				dp[j][i] = max(dp[j][i], dp[j + 1][i - 1] + 2);
			}
			else if (str[j] == 'g' && str[i] == 'c') {
				dp[j][i] = max(dp[j][i], dp[j+ 1][i - 1] + 2);
			}
			for (int k = j; k <= i; k++) {
				dp[j][i] = max(dp[j][i], dp[j][k] + dp[k+1][i]);
			}
			mmx = max(dp[j][i], mmx);
		}
	}*/
	go(0, str.size() - 1);
	cout << dp[0][str.size()-1];
}