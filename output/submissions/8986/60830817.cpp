#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

long long mmx = 1e18;

int n;
int x[100010];

long long f(int mid) {
	long long res = 0;
	for (int i = 1; i < n; i++) {
		res += abs(1LL * mid * i - x[i]);
	}
	return res;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}

	long long l = 0;
	long long r = x[n - 1];
	while (r - l >= 3) {
		long long p = (l * 2 + r) / 3;
		long long q = (l + r * 2) / 3;
		if (f(p) <= f(q)) {
			r = q;
		}
		else {
			l = p;
		}
	}
	long long res = mmx;
	for (long long i = l; i <= r; i++) {
		res = min(f(i), res);
	}
	cout << res;
}