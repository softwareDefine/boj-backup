#include <iostream>

using namespace std;

long long n;

long long sum = 0;
int main()
{
	cin >> n;
	if (n == 1) {
		cout << 1;
	}
	else {
		for (long long i = 1; 1;i++) {
				sum += i;
				if (sum > n) {
					cout << i-1;
					break;
				}
			}
	}
	
}