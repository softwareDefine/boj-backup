#include <iostream>

using namespace std;

int n, m;
char arr1[55][55];
char arr2[55][55];
bool check[55][55];
int diff;
int cnt;

int reverse(int i, int j) {
	if (i + 3 > n || j + 3 > m) {
		return 0;
	}
	for (int a = i; a < i + 3; a++) {
		for (int b = j; b < j + 3; b++) {
			if (!check[a][b]) {
				check[a][b] = true;
			}
			else {
				check[a][b] = false;
			}
		}
	}
	return 1;
}


int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr1[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr2[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr1[i][j] == arr2[i][j]) {
				check[i][j] = false;
			}
			else {
				check[i][j] = true;
				diff++;
			}
		}
	}
	if (n < 3 || m < 3) {
		if (diff == 0) {
			cout << 0;
		}
		else {
			cout << -1;
		}
		return 0;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (check[i][j] == true) {
				if (reverse(i, j)) {
					cnt++;
				}
				else {
					cout << -1;
					return 0;
				}
			}
		}
	}
	cout << cnt;
}