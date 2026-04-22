#include <iostream>
#include <string>

using namespace std;

int n;
int a, b, c;
int main()
{
	cin >> a >> b >> c;
	if (a * 1 + b * 2 + c * 3 >= 10) {
		cout << "happy";
	}
	else {
		cout << "sad";
	}
}