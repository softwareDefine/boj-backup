#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> arr[100010];
long long sum;
int n;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		arr[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) {
		if (!arr[i].empty()) {
			sort(arr[i].begin(), arr[i].end(), [&](auto a, auto b) {
				return a < b;
				});
		}
	}
	for (int i = 1; i <= n; i++) {
		if (!arr[i].empty() && arr[i].size() != 1) {
			for (int j = 0; j < arr[i].size(); j++) {
				//cout << arr[i][j] << ' ';
				int bef = (j != 0) ? arr[i][j - 1] : -9999999999;
				int after = (j != arr[i].size() - 1) ? arr[i][j + 1] : 9999999999;
				sum += (arr[i][j] - bef > after - arr[i][j]) ? after - arr[i][j] : arr[i][j] - bef;
			}
			//cout << '\n';
		}
	}
	cout << sum;
}
