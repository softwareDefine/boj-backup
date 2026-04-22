#include <iostream>

using namespace std;

long long n, m , g;

int main()
{
	cin >> n >> m >> g;
	if (n + m < g*2) {
		cout << n + m;
	}
	else {
		cout << (n + m)-g*2;
	}
}