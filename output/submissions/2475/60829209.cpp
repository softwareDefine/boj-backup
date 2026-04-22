#include <iostream>

using namespace std;

long long a,b,c,d,e;
int main()
{
	cin >> a >> b >> c >> d >> e;
	cout << (a*a + b*b + c*c + d*d + e*e) % 10;
}