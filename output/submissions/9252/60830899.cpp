#include <cmath>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string.h>


using namespace std;
char str1[1010];
char str2[1010];
int lcs[1010][1010];
int mmx;

void answer(int i, int j) {
	if (i == 0 || j == 0) {
		return;
	}
	if (str1[i-1] == str2[j-1]) {
		answer(i - 1, j - 1);
		cout << str2[j - 1];
	}
	else {
		(lcs[i - 1][j] > lcs[i][j - 1]) ? answer(i - 1, j) : answer(i, j - 1);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> str1 >> str2;
	for (int i = 1; i <= strlen(str1); i++) {
		for (int j = 1; j <= strlen(str2); j++) {
			if (str1[i - 1] == str2[j - 1]) {
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
			}
			else {
				lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
			}
		}
	}
	for (int i = 1; i <= strlen(str1); i++) {
		for (int j = 1; j <= strlen(str2); j++) {
			mmx = max(mmx, lcs[i][j]);
		}
	}
	if (mmx == 0) {
		cout << 0;
	}
	else {
		cout << mmx << '\n';
		answer(strlen(str1), strlen(str2));
	}
}