#include <iostream>

using namespace std;
int n;
int fibo1[100010];
int fibo2[100010];
long long fibo[100010];

int fibonacci(int n) {
	if (n == 0) {fibo1[0] = 1;
		return 0;
		
	}if (n == 1) {fibo2[1] = 1;
		return 1;
		
	}
	if (fibo[n]) {
		return fibo[n];
	}
	fibo[n] = fibonacci(n - 1) + fibonacci(n - 2);
	fibo1[n] = fibo1[n - 1] + fibo1[n - 2];
	fibo2[n] = fibo2[n - 1] + fibo2[n - 2];
	return fibo[n];
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		int q;
		cin >> q;
		fibonacci(q);
		cout << fibo1[q] << ' ' << fibo2[q] << '\n';
	}
}