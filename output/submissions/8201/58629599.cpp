#include <iostream>
#include <deque>

using ll = long long;
using namespace std;
ll t, n;
ll arr[3000010];
deque<pair<ll,ll>> mmx;
deque<pair<ll, ll>> mmn;

bool check(int m) {
	mmx.clear();
	mmn.clear();
	for (int i = 1; i <= n; i++) {
		if (!mmx.empty() && mmx.front().first == i - m) {
			mmx.pop_front();
		}
		if (!mmn.empty() && mmn.front().first == i - m) {
			mmn.pop_front();
		}
		while (!mmx.empty() && mmx.back().second <= arr[i]) {
			mmx.pop_back();
		}
		while (!mmn.empty() && mmn.back().second >= arr[i]) {
			mmn.pop_back();
		}
		mmx.push_back({ i,arr[i] });
		mmn.push_back({ i,arr[i] });
		if (mmx.front().second - mmn.front().second <= t && i >= m) {
			return 1;
		}
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	cin >> t >>n;
	for (int i = 1; i <= n; i++) { cin >> arr[i]; }
	ll l = 1;
	ll r = n;
	while (l < r) {
		ll mid = (l + r+1) / 2;
		if (check(mid)) {
			l = mid;
		}
		else {
			r = mid - 1;
		}
	}
	cout << l;
}