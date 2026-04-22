#include <iostream>

#define mod 1000000

using namespace std;

long long fibo[1500010];

long long n;


int main()
{
	cin >> n;
	fibo[0] = 0;
	fibo[1] = 1;
	for (int i = 0; i < 1500000; i++) {
		fibo[i + 2] = (fibo[i + 1] % mod + fibo[i] % mod) % mod;
	}
	cout << fibo[n % 1500000];
}