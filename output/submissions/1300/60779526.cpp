#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>

using ll = long long;
using namespace std;
int n;
int k;
vector<int> vc;
long long finder(int now) {
	ll cnt = 0;
	for (int i = 1; i <= n; i++) {
		cnt += min(now / i,n);
	}
	return cnt;
}
int main()
{
	cin >> n >> k;
	ll l = 1;
	ll r = 1000000000;
	ll mid;
	ll ans;
	while (l <= r) {
		mid = (l + r) / 2;
		if (finder(mid) < k) {
			l = mid +1;
		}
		else {
			ans = mid;
			r = mid -1;
		}
	}
	cout << ans;
}
