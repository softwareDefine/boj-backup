#include <iostream>

using namespace std;

int k, n;
unsigned long long arr[100010];
unsigned long long mmx = 0;

int checker(unsigned long long mid) {
	int cnt = 0;
	for (int i = 0; i < k; i++) {
		cnt += arr[i] / mid;
	}
	return cnt >= n;
}

int main()
{
	cin >> k >> n;
	for (int i = 0; i < k; i++) {
		cin >> arr[i];
		mmx = max(arr[i], mmx);
	}
	unsigned long long l = 0;
	unsigned long long r = mmx;
	unsigned long long mid;
	while (l < r) {
		mid = (l + r + 1) >> 1;
		if (checker(mid)) {
			l = mid;
		}
		else {
			r = mid-1;
		}
	}
	cout << l;
}