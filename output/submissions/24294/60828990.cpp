#include <iostream>
#include <cmath>

using namespace std;

int n;
int a,b,c,d;
int arr[3];
int main()
{
	cin >> a >> b >> c >> d;
	cout << max(a, c) * 2 + (b + d) * 2 + 4;
}