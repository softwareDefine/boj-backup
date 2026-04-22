#include <iostream>

using ll = long long;
using namespace std;
ll n, m;

int arr[5100][5100];
int cnt = 0;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		ll a, b, x;
		cin >> a >> b >> x;
		arr[a][b] += 1;
		arr[a][b + 1] += -1;
		arr[a + x + 1][b] += -1;
		arr[a + x + 1][b + x + 2] += 1;
		arr[a + x + 2][b + 1] += 1;
		arr[a + x + 2][b + x + 2] += -1;
	}
	for (int i = 0; i < 5010; i++) {
		for (int j = 0; j < 5010; j++) {
			int k = (j - 1 < 0) ? 0 : arr[i][j - 1];
			arr[i][j] = arr[i][j] + k;
		}
	}

	for (int i = 0; i < 5010; i++) {
		for (int j = 0; j < 5010; j++) {
			int k = (j - 1 < 0) ? 0 : arr[j - 1][i];
			arr[j][i] = arr[j][i] + k;
		}
	}

	for (int j = 5009; j >= 0; j--) {
		for (int i = 0; i <= 5010; i++) {
			int k = (i - 1 < 0 || i + j - 1 < 0) ? 0 : arr[i + j - 1][i - 1];
			arr[i + j][i] = arr[i + j][i] + k;
			if (i + 1 > 5009 || i + j + 1 > 5009) {
				break;
			}
		}
	}
	for (int i = 0; i < 5010; i++) {
		for (int j = 0; j <= i; j++) {
			if (arr[i][j] > 0) {
				cnt++;
			}
		}
	}
	cout << cnt;
}