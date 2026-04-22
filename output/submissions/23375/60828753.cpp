#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int n;
int a,b,c,d;
int arr[3];
int main()
{
	cin >> a >> b >> c;
    cout << a - c << ' ' << b + c << '\n';
    cout << a + c << ' ' << b + c << '\n';
    cout << a + c << ' ' << b - c << '\n';
    cout << a - c << ' ' << b - c << '\n';
}