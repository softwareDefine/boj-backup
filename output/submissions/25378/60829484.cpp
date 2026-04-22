#include <iostream>

using ll = long long;
using namespace std;

bool check[2510][2510];
ll dp[2510];
ll arr[2510];
int n;

int main()
{
	cin >> n;
	for (int i = 1;i <= n;i++) {
		cin >> arr[i];
	}
	for (int l = 1;l <= n - 1;l++) {
		int current = 1;
		ll buff = arr[l];
		for (int r = l + 1;r <= n;r++) {
			if (buff == arr[r]) {
				check[l][r] = current;
			}
			else {
				check[l][r] = 0;
				if (buff > arr[r]) {
					current = 0;
				}
				buff = abs(buff - arr[r]);
			}
		}
	}
	dp[1] = 1;
	for (int r = 2;r <= n ;r++) {
		dp[r] = dp[r - 1] + 1;
		for (int l = 1;l<r;l++) {
			if (!check[l][r]) { continue; }
			dp[r] = min(dp[r], dp[l - 1] + (r - l));
		}
	}
	cout << dp[n];
}