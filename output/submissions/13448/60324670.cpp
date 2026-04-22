#include <iostream>
#include <algorithm>
#define inf -100000100

using ll = long long;
using namespace std;

ll n, t;
struct input {ll m;ll p;ll r;};

ll dp[55][100010];
input arr[100010];

ll go(ll start, ll time) {
	if (dp[start][time] != inf) {
		return dp[start][time];
	}
	dp[start][time] = go(start + 1, time);
	if (time + arr[start].r <= t) {
		dp[start][time] = max(dp[start][time], go(start + 1, time + arr[start].r) + arr[start].m - (time + arr[start].r) * arr[start].p);
	}
	return dp[start][time];
}

int main()
{
	cin >> n >> t;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].m;
	}
	for (int i = 0; i < n; i++) {
		cin >> arr[i].p;
	}
	for (int i = 0; i < n; i++) {
		cin >> arr[i].r;
	}
	sort(arr, arr + n, [&](auto a, auto b) {
		return a.p * b.r > b.p* a.r;
	});
	for (int i = 0; i < 51; i++) {
		for (int j = 0; j < 100010; j++) {
			dp[i][j] = -100000100;
		}
	}
	cout << go(0, 0);
}