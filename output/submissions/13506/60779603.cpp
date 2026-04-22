#include <iostream>

#include <vector>

#include <string>

using namespace std;

string str;

long long fail[10001000];

int flag = 0;

void preprocessing(string & ptr){

	int n = ptr.size();	int j = 0;

	for (int i = 1; i < n; i++) {

		while (j > 0 && ptr[i] != ptr[j]) { j = fail[j - 1]; }

		if (ptr[i] == ptr[j]) {

			fail[i] = ++j;

		}

		else {

			fail[i] = 0;

		}

	}

}

bool kmp(string &ptr, string &str) {

	int cnt = 0;

	int n = str.size();

	int p = ptr.size();

	int j = 0;

	for (int i = 0; i < n; i++) {

		while (j > 0 && str[i] != ptr[j]) { j = fail[j - 1]; }

		if (str[i] == ptr[j]) {

			if (j == p - 1) {

				cnt++;

				j = fail[j];

			}

			else {

				j++;

			}

		}

	}

	if (cnt >= 3) return 1;

	return 0;

}

int main()

{

	ios_base::sync_with_stdio(0); cin.tie(nullptr);

	cin >> str;

	preprocessing(str);

	int j = str.size()-1;

	if (str.size() == 2) {

		cout << "-1";

	}

	else {

		while (j > 0) {

			string k = str.substr(0, fail[j]);

			if (kmp(k, str)) {

				cout << k;

				flag = 1;

				break;

			}
j = fail[j]-1;
		}

		if (!flag) {

			cout << "-1";

		}

	}

}