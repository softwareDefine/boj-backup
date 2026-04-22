#include <iostream>

using ll = long long;
using namespace std;

int n;
int arr[100010];
int ans[100010];

struct seg {
	ll tree[4000000];
	void update(int node, int left, int right, int pos) {
		if (left > pos || right < pos) {
			return;
		}
		if (left == right) {
			tree[node] = 1;
			return;
		}
		int mid = (left + right) / 2;
		update(node * 2, left, mid, pos);
		update(node * 2 + 1, mid + 1, right, pos);
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}
	ll query(int node, int left, int right, int start,int end) {
		if (right < start || left > end) {
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

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (int i = n; i >= 1; i--) {
		int left = 1;
		int right = n;
		while (left < right) {
			int mid = (left + right) / 2;

/*			for (int j = 1; j <= n; j++) {
				cout << ans[j] << ' ';
			}
			cout << '\n';*/
			ll first = s1.query(1, 1, 1000000, mid+1, 1000000);
			if (n-mid-first > arr[i]) {
				left = mid+1;
			}
			else {
				right = mid;
			}
		}
		s1.update(1, 1, 1000000, left);
		ans[left] = i;
	}
	for (int i = 1; i <= n; i++) {
		if (ans[i] == 0) {
			ans[i] = 1;
			break;
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << ' ';
	}
}