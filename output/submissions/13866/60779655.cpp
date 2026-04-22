#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int a[4];
int main()
{
	for (int i = 0; i < 4; i++) {
		cin >> a[i];
	}
	sort(a, a + 4);
	cout << abs((a[1] + a[2]) - (a[0] + a[3]));
}