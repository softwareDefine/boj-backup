#include <iostream>

using namespace std;

int n;
int a, b, c;

int main()
{
	cin >> n;
	cin >> a >> b >> c;
	int sum = min(a, n) + min(b, n) + min(c, n);
	cout << sum;
}