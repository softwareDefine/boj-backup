#include <iostream>
#include <algorithm>

using namespace std;

char str[100000];

int cmp(char a, char b) {
	return a > b;
}

int main()
{
	cin >> str;
	int szze = sizeof(str) / sizeof(char);
	sort(str, str+szze, cmp);
	cout << str;
}
