#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<long long> lis;
vector<long long> ans;
long long arr[1000010];
long long index[1000010];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	index[0] = 0;
	lis.push_back(arr[0]);
	for (int i = 1; i < n; i++) {
		
		
		if (lis.back() < arr[i]) {
			index[i] = lis.size();
			lis.push_back(arr[i]);
		}
		else {
			index[i] = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
			long long curser = lower_bound(lis.begin(), lis.end(), arr[i])-lis.begin();
			lis[curser] = arr[i];
		}
	}
	cout << lis.size() << '\n';
	int cnt = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (lis.size()-cnt == index[i] + 1) {
			ans.push_back(arr[i]);
			cnt++;
		}
	}
	for (int i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i] << ' ';
	}
}