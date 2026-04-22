#define LLONG_MAX 9223372036854775807
#include <iostream>

using ll = long long;
using namespace std;

ll arr[110];
ll cost[110];
ll dp[11000];
ll n, m;
int flag = 0;
ll mmn = LLONG_MAX;

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> cost[i];
	}
	for (int i = 0; i < n; i++) {
		for (int now = 10000; now >=0; now--) {
			if (now - cost[i] >=0) {
				dp[now] = max(dp[now - cost[i]] + arr[i], dp[now]);
			}
		}
	}
	int i;
	for (i = 0; i <=10000; i++) {
		if (dp[i] >= m) {
			break;
		}
	}
	cout << i;
}