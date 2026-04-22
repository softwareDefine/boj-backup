#include <iostream>
#include <string>
#include <cmath>


using namespace std;

int n;
int a, b, c;
int main()
{
	cin >> a >> b;
	printf("%.1000lf", abs(sqrt(pow(a, 2) + pow(b, 2)) - (a + b)));
}