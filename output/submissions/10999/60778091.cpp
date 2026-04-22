#include <iostream>
#include <vector>

using ll = long long;
using namespace std;

ll n, m, k;
ll arr[1010000];

struct seg {
	ll tree[4000010];
	ll lazy[4000010];
	ll init(int node, int left, int right) {
		if (left == right) {
			tree[node] = arr[left];
			return tree[node];
		}
		int mid = (left + right) / 2;
		return tree[node] = init(node * 2, left, mid) + init(node * 2 + 1, mid + 1, right);
	}
	void update_lazy(int node, int left, int right) {
		if (lazy[node]) {
			tree[node] += (right - left + 1) * lazy[node];
			if (left!=right) {
				lazy[node * 2] += lazy[node];
				lazy[node * 2 + 1] += lazy[node];
			}
			lazy[node] = 0;
		}
	}
	ll query(int node, int left, int right, int start, int end) {
		update_lazy(node, left, right);
		if (right < start || end < left) {
			return 0;
		}
		if (start <= left && right <= end) {
			return tree[node];
		}
		int mid = (left + right) / 2;
		return query(node * 2, left, mid, start, end) + query(node * 2 + 1, mid + 1, right, start, end);
	}
	void update(int node, int left, int right, int start, int end, ll val) {
		update_lazy(node, left, right);
		if (right < start || end < left) {
			return;
		}
		if (start <= left && right <= end) {
			lazy[node] += val;
			update_lazy(node, left, right);
			return;
		}
		int mid = (left + right) / 2;
		update(node * 2, left, mid, start, end, val);
		update(node * 2 + 1, mid + 1, right, start, end, val);
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}
};

seg s1;

int main()
{
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	s1.init(1, 1, n);
	for (int i = 0; i < m + k; i++) {
		int a;
		cin >> a;
		if (a == 1) {
			ll b, c, d;
			cin >> b >> c >> d;
			s1.update(1, 1, n, b, c, d);
		}
		else {
			ll b, c;
			cin >> b >> c;
			cout << s1.query(1, 1, n, b, c) << '\n';
		}
	}
}