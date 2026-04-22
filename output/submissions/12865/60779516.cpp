#include <iostream>

using namespace std;

int n;
int k;
int ks[1100][100100];
int mmx;
int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> a >> b;
		for (int j = 0; j <= k; j++) {
			ks[i][j] = ks[i - 1][j];
			if (j - a >= 0) {
				ks[i][j] = max(ks[i][j], ks[i-1][j-a]+b);
				mmx = max(ks[i][j], mmx);
			}
		}
	}
	cout << mmx;
}