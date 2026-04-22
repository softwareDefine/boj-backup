#include <iostream>
#include <vector>

using namespace std;
int t,s;
int arr[100010];
vector<int> fail(int k) {
	vector<int> ans;
	for (int i = 2; i <= k; i++) {
		if (arr[i] == 1) {
			continue;
		}
		ans.push_back(i);
		for (int j = 2 * i; j <= k; j += i) {
			arr[j] = 1;
		}
	}
	return ans;
}


int main()
{
	cin >> t;
	for (int i = 0; i < t; i++) {
		int flag = 0;
		cin >> s;
		vector<int> ans = fail(s);
		if (ans.empty()) {
			cout << 0 << '\n';
		}
		else {
			for (int j = 0; j < ans.size() && flag!=1; j++) {
				for (int k = 0; k < ans.size() && flag!=1; k++) {
					for (int t = 0; t < ans.size() && flag!=1; t++) {
						if (ans[j] + ans[k] + ans[t] == s) {
							cout << ans[j] << ' ' << ans[k] << ' ' << ans[t] << '\n';
							flag = 1;
							break;
						}
					}
				}
			}
			if (flag == 0) {
				cout << 0 << '\n';
			}
		}
	}
}