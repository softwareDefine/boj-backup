#include <iostream>
#include <math.h>

using namespace std;
int a, b;
int main()
{
	cin >> a >> b;

	cout <<1/(1.0 + pow(10, (b - a) / 400.0));
}
