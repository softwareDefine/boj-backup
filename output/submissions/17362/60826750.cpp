#include <iostream>

using namespace std;

long long a, b, c;
int main()
{
	cin >> a;
	if(a%8==1){
		cout << "1";
	}
	else if (a % 8 == 0 || a % 8 == 2) {
		cout << "2";
	}
	else if (a % 8 == 3 || a % 8 == 7) {
		cout << "3";
	}
	else if (a % 8 == 4 || a % 8 == 6) {
		cout << "4";
	}
	else {
		cout << "5";
	}
}