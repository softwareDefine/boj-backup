#include <iostream>
#include <math.h>

using namespace std;

int n, m, k;
long long timer=1;
int cnt;
int main()
{
	cin >> n >> m >> k;
	cout << n - abs(m - k);
}