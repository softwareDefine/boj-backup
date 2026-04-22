#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[1000010];
int sum = 0;
int cnt = 0;

int check() {
	for (int i = 0; i < n; i++) {
		if (arr[i] != 0) {
			return 1;
		}
	}
	return 0;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n, [&](auto a, auto b) {
		return a > b;
	});
	while(check()) {
		if (arr[0] != 0 && arr[1] == 0) {
			sum += arr[0];
			break;
		}
		sum += min(arr[0], arr[1]);
		cnt = min(arr[0], arr[1]);
		arr[0] -= cnt;
		arr[1] -= cnt;
		if (arr[0] < 0) arr[0] = 0;
		if (arr[1] < 0) arr[1] = 0;
		sort(arr, arr + n, [&](auto a, auto b) {
			return a > b;
		});
	}
	if (sum > 1440) {
		cout << -1;
	}
	else {
		cout << sum;
	}
}