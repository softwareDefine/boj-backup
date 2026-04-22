#include <iostream>

using namespace std;

string str;
int chk[4];
int same1;
int same2;
bool flag;
int main()
{
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'U'|| str[i] =='C') {
			if (str[i] == 'U') {
				chk[0]++;
			}
			else {
				chk[1]++;
			}
		}
		else if (str[i] == 'D' || str[i] == 'P') {
			if (str[i] == 'D') {
				chk[2]++;
			}
			else {
				chk[3]++;
			}
		}
	}
	if (chk[0]+chk[1] > (chk[2]+chk[3])/2 + (chk[2]+chk[3])%2) {
		cout << "U";
		flag = 1;
	}
	if (chk[2]+chk[3] > 0) {
		cout << "D";
		flag = 1;
	}if (chk[2]+chk[3] > 0) {
		cout << "P";
		flag = 1;
    }
}