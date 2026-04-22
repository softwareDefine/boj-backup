#include <iostream>
#include <string>

using namespace std;

int n, m;
int suma, sumb;
bool flag;
string str;
int main()
{
	cin >> str;
	for (int i = 0; i < str.length(); i+=2) {
		if(flag == true && abs(suma - sumb) == 2) {
			break;
		}
		if (str[i] == 'A') {
			suma += str[i + 1];
		}
		else if (str[i] == 'B') {
			sumb += str[i + 1];
		}
		if (suma == 10 && sumb== 10) {
			flag = true;
		}
	}
	if (suma > sumb) {
		cout << "A";
	}
	else {
		cout << "B";
	}
}