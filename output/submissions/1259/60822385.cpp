#include <iostream>

using namespace std;

string a;
int main()
{
	while (1) {
		int flag = 0;
		cin >> a;
		if (a[0] == '0') {
			break;
		}
		for (int i = 0; i < a.length() / 2; i++) {
			if (a[i] != a[a.length()-1 - i]) {
				cout << "no" << '\n';
				flag = 1;
				break;
			}
				
		}
		if (flag == 0) {
			cout << "yes" << '\n';
		}
	}
}