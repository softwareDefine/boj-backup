#include <iostream>
#include <math.h>

using namespace std;

long long a,b,c,d,e;
int suma,sumb;

int main()
{
	cin >> a >> b >> c >> d;
	suma = a + b + c + d;
	cin >> a >> b >> c >> d;
	sumb = a + b + c + d;
	cout << max(suma, sumb);
}
