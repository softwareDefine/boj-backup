#include <iostream>
#include <stack>

using namespace std;
int arr[1000101];
pair<int, int> dp[1000101];
int n;
stack<pair<int, int>> st;
stack<pair<int, int>> st2;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		dp[i].first = -99999999;
	}
	for (int i = 1; i <= n; i++) {
		while(!st.empty() && st.top().second <= arr[i]) {
			st.pop();
		}
		if (!st.empty()) {
			dp[i].first = st.top().first;
		}
		dp[i].second = st.size();
		st.push({ i,arr[i] });
	}
	for (int i = n; i >= 1; i--) {
		while (!st2.empty() && st2.top().second <= arr[i]) {
			st2.pop();
		}
		if (!st2.empty()) {
			dp[i].first = (abs(dp[i].first-i) > abs(st2.top().first-i))?st2.top().first:dp[i].first;
		}
		dp[i].second += st2.size();
		st2.push({ i,arr[i] });
	}
	for (int i = 1; i <= n; i++) {
		if (dp[i].second == 0) {
			cout << 0 << '\n';
			continue;
		}
		cout << dp[i].second << ' ' << dp[i].first << '\n';
	}
}