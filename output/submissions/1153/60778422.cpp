#include <iostream>
#include <vector>

using namespace std;

int arr[1000010];
int n;

vector<int> factor(int n) {
	vector<int> ans;
	for (int i = 2; i <= n; i++) {
		if (arr[i]) continue;
		ans.push_back(i);
		for (int j = i * 2; j <= n; j+=i) {
			arr[j] = 1;
		}
	}
	return ans;
}

int main()
{
	cin >> n;
	auto ans = factor(n);
	if (n <= 7) {
		cout << -1;
	}
	else {
		if (n % 2 == 0) {
			for (int i = 2; i <= n; i++) {
				if (!arr[i] && !arr[n - i - 4]) {
					cout << 2 << ' ' << 2 << ' ' << i << ' ' << n - i - 4;
					break;
				}
			}
		}
		else {
			for (int i = 2; i <= n; i++) {
				if (!arr[i] && !arr[n - i - 5]) {
					cout << 2 << ' ' << 3 << ' ' << i << ' ' << n - i - 5;
					break;
				}
			}
		}
	}
}