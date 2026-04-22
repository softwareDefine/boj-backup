#include <iostream>
#include <algorithm>

using namespace std;

int a;
int main()
{
	cin >> a;
	printf("%.1000lf\n%.1000lf", 100.0 / a, 100.0 / (100 - a));
}