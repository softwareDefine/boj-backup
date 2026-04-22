#include <iostream>
#include <math.h>

using namespace std;

long long n, m;
long long arr[1000010];

long long checker(long long h) {
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		sum += max<long long>(arr[i] -h, 0);
	}
	return sum >= m;
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	long long l = 0;
	long long r = 2000000000;
	int mid;
	while (l < r) {
		mid = (l + r+1) >> 1;
		if (checker(mid)) {
			l = mid;
		}
		else {
			r = mid - 1;
		}
	}
	cout << l;
}
