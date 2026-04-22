#include <iostream>
using namespace std;

long long a, b, c, d;
char arr[110][110];

int main() {
	cin >> a >> b >> c >> d;
	if (a-c >= 2 && b-d>=2) {
		cout << 1;
	}
	else {
		cout << 0;
	}
}