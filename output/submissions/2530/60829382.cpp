#include <iostream>

using namespace std;

int a, b, c,d;

int main()
{
	cin >> a >> b >> c;
	cin >> d;
	a += d / 3600;
	b += (d % 3600) / 60;
	c+=(d % 3600) % 60;
	b += c / 60;c = c % 60;
	a += b / 60;b = b % 60;
	a = a % 24;
	cout << a << " " << b << " " << c;
}