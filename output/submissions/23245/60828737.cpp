#include <iostream>
#include <algorithm>

using ll = long long;
using namespace std;
int n;
ll ans;
pair<ll,ll> arr[1000010];

struct seg {
	ll tree[1 << 21];
	void update(int node, int pos, int left, int right,int val) {
		if (left > pos || right < pos) {
			return;
		}
		if (left == right) {
			tree[node] += val;
			return;
		}
		int mid = (left + right) / 2;
		update(node * 2, pos, left, mid,val);
		update(node * 2 + 1, pos, mid + 1, right, val);
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}
	ll query(int node, int left, int right, int start, int end) {
		if (right < start || end < left) {
			return 0;
		}
		if (start <= left && right <= end) {
			return tree[node];
		}
		int mid = (left + right) / 2;
		return query(node * 2, left, mid, start, end) + query(node * 2 + 1, mid + 1, right, start, end);
	}
};
seg s1;
seg s2;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].first;
	}
	for (int i = 0; i < n; i++) {
		cin >> arr[i].second;
	}
	sort(arr, arr + n, [&](pair<int, int> a, pair<int, int> b) {
		if (a.first == b.first) {
			return a.second > b.second;
		}
		return a.first < b.first;
	});
	for (int i = 0; i < n; i++) {
		ll before = s1.query(1, 0, 1000000, 0, arr[i].second-1);
		s1.update(1, arr[i].second, 0,1000000,1);
		s2.update(1, arr[i].second, 0,1000000,before);
		ans += s2.query(1, 0, 1000000, 0, arr[i].second - 1);
	}
	cout << ans;
}