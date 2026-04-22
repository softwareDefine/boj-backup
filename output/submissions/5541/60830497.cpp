#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>

using ll = long long;
using namespace std;
ll n, m;

int arr[5100][5100];
int cnt = 0;
int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, x;
		scanf(" %d %d %d", &a, &b, &x);
		arr[a][b]++;
		arr[a][b + 1]--;
		arr[a + x+1][b]--;
		arr[a + x+1][b + x+2]++;
		arr[a + x + 2][b+1]++;
		arr[a + x + 2][b + x+2]--;
	}
	for (int i = 1; i < n+4; i++) {
		for (int j = 1; j < n+4; j++) {
			arr[i][j] = arr[i][j] + arr[i][j - 1];
		}
	}
	for (int i = 1; i < n+4; i++) {
		for (int j = 1; j < n+4; j++) {
			arr[j][i] += arr[j - 1][i];
		}
	}
	for (int i = 1; i < n+4; i++) {
		for (int x = i,y=1;x<n+4; x++,y++) {
			arr[x][y] += arr[x-1][y - 1];
		}
	}
	for (int i = 0; i < n+4; i++) {
		for (int j = 0; j <= i; j++) {
			if (arr[i][j]) {cnt++;}
		}
	}
	printf("%d", cnt);
}