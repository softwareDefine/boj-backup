#include <iostream>
#include <algorithm>

using namespace std;

int n;
int dp[1100][1001];
int mmx;
pair<int, int> pr[100010];

int main()
{
	for (int i = 0; i < 1001; i++) {
		dp[i][1] = 1;
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> pr[i].first;
		cin >> pr[i].second;
	}
	sort(pr, pr + n, [&](pair<int, int> a, pair<int, int> b) {
		if (a.first == b.first) {
			return a.second > b.second;
		}
		return a.first > b.first;
	});
	for (int use = 1; use <= n; use++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) {
					continue;
				}
				if (((pr[i].first >= pr[j].first && pr[i].second >= pr[j].second) || (pr[i].first >= pr[j].second && pr[i].second >= pr[j].first)) && dp[i][use]) {
					dp[j][use + 1] = dp[i][use] + 1;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 1010; j++) {
			if (dp[j][i]) {
				mmx = max(i, mmx);
			}
		}
	}
	cout << mmx;
}