#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;
using namespace std;
ll arr[1000010];
ll n, m, k;
ll dp[1000010];
ll start;
ll mmx;
ll visit[1000010];
ll go(ll end){
	if (end  < 0) {
		return 0;
	}
	if (visit[end]) {
		return dp[end];
	}
	if (end - k >= 0) {
		dp[end] = go(end - k) + arr[end];
		if (dp[end] <= m) {
			mmx = max(end, mmx);
			go(end - k);
		}
	}
}

int main()
{
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	sort(arr+1, arr + n+1, [&](int a, int b) {
		return a < b;
	});
	for (ll i = 1; i <= n; i++) {
		ll first = (i - k > 0) ? dp[i - k] : 0;
		dp[i] = first + arr[i];
		if (dp[i] <= m) {
			mmx = max(i,mmx);
		}
	}
	cout << mmx;
}