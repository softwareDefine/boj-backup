#include <iostream>

using ll = long long;
using namespace std;

int n;
ll idx;

struct seg {
	ll tree[10000010];
	void update(int node, int left, int right, int pos) {
		if (right < pos || pos < left) {
			return;
		}
		if (left == right) {
			tree[node] += 1;
			return;
		}
		int mid = (left + right) / 2;
		update(node * 2, left, mid, pos);
		update(node * 2 + 1, mid + 1, right, pos);
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}
	void query(int node, int left, int right, int pos) {
		if (left == right) {
			tree[node] -= 1;
			idx = left;
			return ;
		}
		int mid = (left + right) / 2;
		if (pos - tree[node * 2] >= 0) {
			 query(node * 2 + 1, mid + 1, right, pos - tree[node * 2]);
		}
		else {
			 query(node * 2, left, mid, pos);
		}
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}
};

seg s1;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		if (a == 1) {
			s1.update(1, 1, 2000000, b);
		}
		else {
			s1.query(1, 1, 2000000, b - 1);
			cout << idx << '\n';
		}
	}
}