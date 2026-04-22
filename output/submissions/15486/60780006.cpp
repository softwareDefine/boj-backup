#include <iostream>

using namespace std;

pair<int, int> arr[1501100];
int dp[1501100];
int n;
int mmx;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	for (int i = 0; i < n; i++) {
		dp[arr[i].first + i] = max(dp[i]+arr[i].second,dp[arr[i].first+i]);
		dp[i + 1] = max(dp[i], dp[i + 1]);
	}
	for (int i = 0; i < n+1; i++) {
		mmx = max(dp[i],mmx);
	}
	cout << mmx;
}