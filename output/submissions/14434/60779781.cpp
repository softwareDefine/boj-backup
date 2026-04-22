#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;
using namespace std;

int n, m, k, q;

int arr[200100];
vector<int> child[200100];
int date[2000100];

int main()
{
	cin >> n >> m >> k >> q;
	for (int i = 1; i <= m; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= k; i++) {
		int ac;
		cin >> ac;
		child[ac].push_back(i);
	}
	for (int i = 1; i <= q; i++) {
		int child1, child2,lim;
		cin >> child1 >> child2 >> lim;
		ll left = 1;
		ll right = 200010;
		while (left < right) {
			ll mid = (left + right) / 2;
			ll first =  upper_bound(child[child1].begin(), child[child1].end(), mid) - child[child1].begin();
			ll second = upper_bound(child[child2].begin(), child[child2].end(), mid) - child[child2].begin();
			if (first+second < arr[lim]) {
				left = mid+1;
			}
			else {
				right = mid;
			}
		}
		if (left == 200010) {
			continue;
		}
		date[left]++;
	}
	long long sum = 0;
	for (int i = 1; i <= k; i++) {
		sum += date[i];
		cout << sum << '\n';
	}
}