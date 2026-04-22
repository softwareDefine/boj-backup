#include <iostream>
#include <string>

using namespace std;

int cnt = 1;
int main()
{
	int n;
	string str;
	cin >> n;
	n += 3071;
	str.push_back(n / 4096 + 234);
	str.push_back(n / 64 % 64 + 128);
	str.push_back(n % 64 + 128);
	cout << str;
}