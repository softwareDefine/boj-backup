#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string.h>

char str1[1010];
char str2[1010];
int lcs[1010][1010];
int mmx;

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> str1 >> str2;
	for (int i = 1; i <= strlen(str1); i++) {
		for (int j = 1; j <= strlen(str2); j++) {
			if (str1[i-1] == str2[j-1]) {
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
	cout << mmx;
}