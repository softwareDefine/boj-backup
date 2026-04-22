#include <iostream>

using namespace std;

long long a, b,c,d;
long long sum=1;
int main()
{
	cin >> a ;
	for (int i = 1; i <= a; i++) {
		sum = (sum % 10) * (i % 10);
	}
	cout << sum % 10;
}