#include <iostream>

using ll = long long;
using namespace std;

string str, ptr;
ll dp[26][1000010];
ll av[26];
ll cnt;
int main()
{
	cin >> str;
	cin >> ptr;
	for (int i = 0; i < ptr.size(); i++) {
		av[ptr[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		if (av[i]) {
			for (int j = ptr.size() - 1; j >= 0; j--) {
				if (ptr[j] == char(i + 'a')) {
					dp[i][j] = j;
				}
				else {
					if (j == ptr.size() - 1) {
						dp[i][j] = -1;
					}
					else {
						dp[i][j] = dp[i][j + 1];
					}
				}
			}
		}
	}
	int last = 0;
	cnt = 1;
	for (int i = 0; i < str.size(); i++) {
		if (!av[str[i] - 'a']) {
			cnt = -1;
			break;
		}
		int check = dp[str[i]-'a'][last];
		if (check == ptr.size()-1 && i != str.size()-1) {
			last = 0;
			cnt++;
		}
		else if (check == -1) {
			last = dp[str[i]-'a'][0]+1;
			cnt++;
		}
		else {
			last = check + 1;
		}
	}
	cout << cnt;
}