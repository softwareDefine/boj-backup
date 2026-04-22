#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int n;
int main()
{
	cin >> n;
	while (n) {
		cout << "long" << " ";
		n -= 4;
	}
	cout << "int";
	return 0;
}