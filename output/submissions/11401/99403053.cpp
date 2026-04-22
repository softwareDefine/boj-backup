#define mod 1000000007
#include <bits/stdc++.h>

using lint = long long;
using namespace std;
lint n, k;

lint reverser(lint x,lint n) {
	if (n == 0) {
		return 1;
	}
	if (n == 1) {
		return x % mod;
	}
	lint ans = reverser(x, n / 2) % mod;
	if (n % 2 == 0) {
		return ((ans * ans) % mod);
	}
	else {
		return (((ans * ans) % mod) * x) % mod;
	}
}

void get(int n, int k) {
	lint sum = 1;
	for (int i = n; i > n - k; i--) {
		sum = ((sum%mod)*(i%mod))%mod;
	}
	for (int i = 1; i <= k; i++) {
		sum = ((sum%mod)*(reverser(i,1000000005)%mod))%mod;
	}
	cout << sum;
}

int main()
{
	cin >> n >> k;
	get(n, k);
}