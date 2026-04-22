#include <iostream>

using namespace std;

int n, m, b;
pair<int, int> mmx = { 9999999999,9999999999 };
int hmmx = -9999999999;
int hmnx = 9999999999;
int arr[600][600];
int main()
{
	cin >> n >> m >> b;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			hmnx = min(arr[i][j], hmnx);
			hmmx = max(arr[i][j], hmmx);
		}
	}
	for (int h = hmnx; h <= hmmx; h++) {
		int sum = 0;
		int flag = 0;
		int limitblock = b;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] - h == 0) {
					continue;
				}if (arr[i][j] - h > 0) {
					sum += (arr[i][j] - h) * 2;
					limitblock += (arr[i][j] - h);
				}
				else {
					sum += (h - arr[i][j]);
					limitblock += ( arr[i][j]-h);
				}
			}
		}
		if (limitblock < 0) {
				flag = 1;
		}
		if (mmx.first >= sum && !flag) {
			mmx.first = sum;
			mmx.second = h;
		}
	}
	cout << mmx.first << ' ' << mmx.second;
}