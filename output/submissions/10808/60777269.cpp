#include <iostream>
#include <string>

using namespace std;

string str;

int arr[30];

int main()
{
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		arr[str[i]-'a']++;
	}
	for (int i = 0; i < 26; i++) {
		cout << arr[i] << ' ';
	}
}