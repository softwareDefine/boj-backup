#include <iostream>

using namespace std;
int n, k;
void get(int n, int k) {
	int sum = 1;
	for (int i = n; i > n - k; i--) {
		sum *= i;
	}
	for (int i = 1; i <= k; i++) {
		sum /= i;
	}
	cout << sum;
}

int main()
{
	cin >> n >> k;
	get(n, k);
}