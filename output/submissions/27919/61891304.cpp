#include <iostream>

using namespace std;

string str;
int chk[4];
bool flag;
int main()
{
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'U'|| str[i] =='C') {
			chk[0]++;
		}
		else if (str[i] == 'D' || str[i] == 'P') {
			chk[1]++;
			chk[2]++;
		}
	}
	if (chk[0] > chk[1] || chk[0] > chk[2]) {
		cout << "U";
		flag = 1;
	}
	if (chk[1] >= 0) {
		cout << "D";
		flag = 1;
	}if (chk[2] >= 0) {
		cout << "P";
		flag = 1;
	}
}