#include <iostream>

using ll = long long;
using namespace std;

ll cost, n;
bool visit[1000010];
ll dp[1000010];
ll mmn = 999999;
pair < ll, ll> arr[100010];


int main()
{
	for (int i = 0; i < 100010; i++) {
		dp[i] = 9999999;
	}
	cin >> cost >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].first;
		cin >> arr[i].second;
	}
	dp[0] = 0;
	for (int j = 0; j <= cost; j++) {
		for (int i = 0; i < n; i++) {
			dp[j + arr[i].second] = min(dp[j] + arr[i].first, dp[j + arr[i].second]);
		}
	}
	for (int i = cost; i < 100010; i++) {
		mmn = min(dp[i], mmn);
	}
	cout << mmn;
}