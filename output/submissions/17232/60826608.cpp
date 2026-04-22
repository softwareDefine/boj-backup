#include <iostream>

using namespace std;

int n, m,t;
int a, b, k;
char con[1011][1011];
char conn[1011][1011];
int arr[1011][1011] = { 0, };
int main()
{
	cin >> n >> m >> t;
	cin >> k >> a >> b;
	for (int i = 0; i < n; i++) {
		cin >> conn[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			con[i][j] = conn[i - 1][j - 1];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			conn[i][j] = '.';
		}
	}
	while (t--) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				arr[i][j] = arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
				if (con[i][j] == '*') {
					arr[i][j]++;
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				int cnt = arr[min(i + k, n)][min(j + k, m)]- arr[min(i + k, n)][max(j - k, 1)-1]- arr[max(i - k, 1)-1][min(j + k, m)] +arr[max(i - k, 1)-1][max(j - k, 1)-1];
				if (con[i][j] == '*') {
					cnt--;
					if (cnt >= a && cnt <= b) {
						conn[i][j] = '*';
					}
					else if (cnt < a || cnt > b) {
						conn[i][j] = '.';
					}
					else {
						conn[i][j] = '.';
					}
				}
				else {
					if (cnt > a && cnt <= b) {
						conn[i][j] = '*';
					}
					else {
						conn[i][j] = '.';
					}
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				con[i][j] = conn[i][j];
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << con[i][j];
		}
		cout << '\n';
	}
}