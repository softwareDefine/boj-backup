#include <iostream>

using namespace std;

int n, m;

int main()
{
	cin >> n >> m;
	if (m == 1 || m==2) {
		cout << "NEWBIE!";
	}
	else if (m <= n) {
		cout << "OLDBIE!";
	}
	else {
		cout << "TLE!";
	}
}