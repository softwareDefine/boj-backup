#include <iostream>

using namespace std;

long long a, b, c, d, e;
long long timer;
int main()
{
	cin >> a >> b >> c;
	cout << max(a * b / c, a * c / b);
}