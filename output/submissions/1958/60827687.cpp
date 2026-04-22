#include <iostream>

using namespace std;

string a, b, c;
int arr[110][110][110];
int mmx;

int main()
{
	cin >> a >> b >> c;
	for (int i = 1; i <= a.length(); i++) {
		for (int j = 1; j <= b.length(); j++) {
			for (int k = 1; k <= c.length(); k++) {
				if (a[i - 1] == b[j - 1] && b[j - 1] == c[k - 1]) {
					arr[i][j][k] = arr[i - 1][j - 1][k - 1] + 1;
				}
				else {
					arr[i][j][k] = max(max(arr[i - 1][j][k], arr[i][j - 1][k]), arr[i][j][k - 1]);
				}
				mmx = max(arr[i][j][k],mmx);
			}
		}
	}
	cout << mmx;
}