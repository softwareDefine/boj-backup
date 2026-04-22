#include <iostream>
#include <algorithm>

using namespace std;

long long n, m;
long long arr[100100];

int checker(long long mid) {
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		sum += min(arr[i],mid);
	}
	return sum <= m;
}

int main()
{
	cin >> n;
	long long r;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		r = max(arr[i],r);
	}
	sort(arr, arr + n);
	cin >> m;
	long long l = 0;
	long long mid;
	long long mmx = 0;
	while (l < r) {
		mid = (l + r+1) >> 1;
		if (checker(mid)) {
			l = mid;
			for (int i = 0; i < n; i++) {
				mmx = max(min(arr[i], mid),mmx);
			}
		}
		else{
			r = mid-1;
		}
	}
	cout << mmx;
}