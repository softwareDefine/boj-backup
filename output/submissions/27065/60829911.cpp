#include <iostream>

using namespace std;

int t;

int main(int argc, char* argv[])
{
	cin >> t;
	while (t--) {
		int n;
		long long sum = 0;
		int flag = 0;
		cin >> n;
		for (int i = 1; i < n; i++) {
			int minsum = 0;
			if (n % i == 0) {
				sum += i;
				for (int j = 1; j < i; j++) {
					if (i % j == 0) {
						minsum += j;
					}
				}
				if (minsum > i) {
					flag = 1;
					break;
				}
			}
		}
		if (sum > n && flag == 0) {
			cout << "Good Bye";
		}
		else {
			cout << "BOJ 2022";
		}cout << "\n";
	}
}