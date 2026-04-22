#include <iostream>
#define mod 1000000007

using namespace std;

int n;
long long a, b;
long long all;

long long pow1(long long c,long long k) {
	if (k == 0) {
		return 1;
	}
	if (k == 1) {
		return c%mod;
	}
	long long ans = pow1(c, k / 2)%mod;
	if (k % 2 == 1) {
		return (((ans * ans)%mod) * c)%mod;
	}
	else {
		return (ans * ans)%mod;
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		if (b == 0) {
			continue;
		}
		all = ((a * b)%mod * (pow1(2, b - 1) % mod) + all) % mod;
	}
	cout << all % mod;
}