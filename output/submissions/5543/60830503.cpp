#include <iostream>
#include <algorithm>

using namespace std;

long long a, b, c, e, f;
long long arr[1000];

int main()
{
	cin >> a >> b >> c;
	cin >> e >> f;
	cout << min(a, min(b, c)) + min(e, f)-50;
}