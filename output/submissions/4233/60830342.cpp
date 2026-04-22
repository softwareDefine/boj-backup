// a-160.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

int checker(long long a) {
	if (a == 1) {
		return 1;
	}
	for (long long i = 2; i * i <= a; i++) {
		if (a % i == 0) {
			return 1;
		}
	}
	return 0;
}

long long modpow(long long x, long long n, long long mod) {
	if (n == 0) {
		return 1;
	}
	if (n == 1) {
		return x % mod;
	}
	long long ans = modpow(x, n / 2,mod) % mod;
	if (n % 2 == 0) {
		return ((ans * ans) % mod);
	}
	else {
		return (((ans * ans) % mod) * x) % mod;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while (1) {
		long long a, b;
		cin >> a >> b;
		if (a == 0 && b == 0) {
			break;
		}
		if (checker(a) == 1) {
			if (modpow(b,a,a)==b) {
				cout << "yes"<<'\n';
			}
			else {
				cout << "no"<<'\n';
			}
		}
		else {
			cout << "no"<<'\n';
		}
	}
}