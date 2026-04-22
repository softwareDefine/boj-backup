#include <iostream>

using namespace std;

int tree[1 << 22];
int idx;

struct seg {
	int init(int node, int left, int right) {
		if (left == right) {
			return tree[node] = 1;
		}
		int mid = (left + right) / 2;
		return tree[node] = init(node * 2, left, mid) + init(node * 2 + 1, mid + 1, right);
	}
	int update(int node, int left, int right, int pos) {
		if (pos < left || right < pos) {
			return tree[node];
		}
		if (left == right) {
			tree[node] = 0;
			return tree[node];
		}
		int mid = (left + right) / 2;
		return tree[node] = update(node * 2, left, mid, pos) + update(node * 2 + 1, mid + 1, right, pos);
	}
	int query(int node, int left, int right,int pos) {
		if (left == right) {
			return left;
		}
		int mid = (left + right) / 2;
		if (pos > tree[node * 2]) {
		 return query(node * 2 + 1, mid + 1, right, pos - tree[node * 2]);
		}
		else {
			return query(node * 2, left, mid, pos);
		}
	}
};
seg s1;

int main()
{
	int n, k;
	cin >> n >> k;
	s1.init(1, 1, n);
	int szze = k;
	cout << "<";
	for (int i = 1; i <= n; i++) {
		szze %= n - i + 1;
		if (szze == 0) {
			szze = n - i + 1;
		}
		int num = s1.query(1, 1, n, szze);
		s1.update(1, 1, n, num);
		cout << num ;
		if (i != n) {
			cout << ", ";
		}
		szze += (k - 1);
	}
	cout << ">";
}