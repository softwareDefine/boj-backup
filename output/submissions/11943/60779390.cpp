#include <iostream>
#include <math.h>
#include <string.h>
#include <string>

using namespace std;

int a,b,c,d,e;
int suma,sumb;

int main()
{
	cin >> a >> b;
	cin >> c >> d;
	cout << min(a + d, c + b);
}