#include <iostream>

using ll = long long;
using namespace std;

ll mmp[10001000];
ll arr[10001000];
int n, m;

ll check(ll mid) {
	for (int i = 0; i < m; i++) {
		ll one = (arr[i] - mid < 0) ? 0 : (arr[i] - mid);
		ll two =  ((arr[i] + mid+1)<=n)?(arr[i]+mid+1):(n+1);
		mmp[one] += 1;
		mmp[two] += -1;
	}
	ll status = 0;
	for (ll i = 0; i <= n; i++) {
		status += mmp[i];
		if (status ==0) {
			for (ll j = 0; j <= n; j++) {
				mmp[j] = 0;
			}
			return 0;
		}
	}
	return 1;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> arr[i];
	}
	ll left = 0;
	ll right = n;
	while (left < right) {
		ll mid = (left + right) / 2;
		if (check(mid)) {
			right = mid;
		}
		else {
			left = mid+1;
		}
	}
	cout << left;
}