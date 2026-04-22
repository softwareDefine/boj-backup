#include <iostream>
#include <cmath>

using namespace std;

int n;
int a,b,c,d;
int arr[3];
int main()
{
	cin >> a >> b;
	cout << max(a + b,a-b) <<'\n' << min(a - b,a+b);
}