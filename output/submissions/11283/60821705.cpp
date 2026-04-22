#include <iostream>
#include <string>

using namespace std;

int cnt = 1;
int main()
{
	int n;
	string str;
	cin >> str;
	n = ((str[0] & 255)-234) * 4096 + ((str[1] & 255) - 176) * 64 + (str[2] & 255) - 127;
	cout << n;
}