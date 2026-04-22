#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int arr[100010],brr[100010],crr[100010];
int n;
int index[100010];
vector<int> ans;
vector<int> lis;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		arr[a] = i;
		crr[i] = a;
	}
	for (int i = 0; i < n; i++) {
		cin >> brr[i];
		brr[i] = arr[brr[i]];
	}
	index[0] = 0;
	lis.push_back(arr[0]);
	for (int i = 1; i < n; i++) {
		if (lis.back() < brr[i]) {
			index[i] = lis.size();
			lis.push_back(brr[i]);
		}
		else {
			index[i] = lower_bound(lis.begin(), lis.end(), brr[i]) - lis.begin();
			int curser = lower_bound(lis.begin(), lis.end(), brr[i]) - lis.begin();
			lis[curser] = brr[i];
		}
	}
	cout << lis.size() << '\n';
	int cnt = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (lis.size() - cnt == index[i] + 1) {
			ans.push_back(crr[brr[i]]);
			cnt++;
		}
	}
	sort(ans.begin(), ans.end(), [&](auto a, auto b) {return a < b; });
	for (int i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i] << ' ';
	}
}