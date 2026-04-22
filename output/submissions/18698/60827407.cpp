#include <iostream>
#include <string>

using namespace std;

int n;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		int cnt = 0;
		cin >> str;
		for (int j = 0; j < str.length(); j++) {
			if (str[j] == 'D') {
				break;
			}
			cnt++;
		}
		cout << cnt << '\n';
	}
}