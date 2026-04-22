#include <iostream>
#include <math.h>

using namespace std;

int n, m, k,g;
long long timer=1;
int cnt;
int main()
{
	cin >> n >> m >> k >> g;
	cout << min(n, (m / g) * (k / g));
}