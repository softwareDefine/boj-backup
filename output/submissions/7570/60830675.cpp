#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;
using namespace std;

ll mmx;
ll n;
ll arr[1000100];
ll dp[1000100];
vector<ll> vc;

int main()
{
	fill(dp, dp + 1000010, 1);
	cin >> n;
	for (int i = 1;i <= n;i++) {
		ll a;
		cin >> a;
		arr[a] = i;
	}
	for (int i = 2;i <= 1000010;i++) {
		if (arr[i] && arr[i - 1]) {
			if (arr[i] > arr[i - 1]) {
				dp[i] = dp[i - 1]+1;
				mmx = max(mmx, dp[i]);
			}
		}
	}
	if (n == 1) {
		cout << 0;
	}
	else {
		cout << n - mmx;
	}
}