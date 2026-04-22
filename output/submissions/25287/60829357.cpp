#include <iostream>

using ll = long long;
using namespace std;

int t;

int main()
{
	cin >> t;
	while (t--) {
		ll n = 0;
		ll mmn;
		ll mmx;
		ll flag = 0;
		ll arr[50010] = { 0, };
		bool changed[50010] = { 0, };
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		if (arr[0] > n - arr[0] + 1) {
			arr[0] = n - arr[0] + 1;
		}
		for (int i = 1; i < n; i++) {
			if (arr[i - 1] <= arr[i]) {
				if (arr[i - 1] <= n - arr[i] + 1 && arr[i] - arr[i - 1] >= n - arr[i] + 1 - arr[i - 1]) {
					arr[i] = n - arr[i] + 1;
				}
			}
			else {
				arr[i]= n - arr[i] + 1;
			}
		}
		for (int i = 0; i < n - 1; i++) {
			if (!(arr[i] <= arr[i + 1])) {
				flag = 1;
				break;
			}
		}
		if (flag) {
			cout << "NO" << '\n';
		}
		else {
			cout << "YES" << '\n';
		}
	}
}