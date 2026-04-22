#include <iostream>

using ll = long long;
using namespace std;
ll n, q;
ll tree[1 << 22];
ll lazy[1 << 22];

struct seg {
	void update_lazy(int node, int left, int right) {
		if (lazy[node]) {
			tree[node] = (right - left + 1)-tree[node];
			if (left != right) {
				lazy[node * 2] += lazy[node];
				lazy[node * 2] %= 2;
				lazy[node * 2 + 1] += lazy[node];
				lazy[node * 2 + 1] %= 2;
			}
		}
		lazy[node] = 0;
	}
	void update(int node,int left,int right, int start, int end, int val) {
		update_lazy(node, left, right);
		if (right < start || end < left) {
			return;
		}
		if (start <= left && right <= end) {
			tree[node] = (right - left + 1)-tree[node];
			if (left != right) {
				lazy[node * 2] += val;
				lazy[node * 2] %= 2;
				lazy[node * 2 + 1] += val;
				lazy[node * 2 + 1] %= 2;
			}
			return;
		}
		ll mid = (left + right) / 2;
		update(node * 2, left, mid, start, end, val);
		update(node * 2 + 1, mid + 1, right, start, end, val);
		tree[node] = tree[node * 2] + tree[node*2+1];
	}
	ll query(int node, int left, int right, int start, int end) {
		update_lazy(node, left, right);
		if (right < start || end < left) {
			return 0;
		}
		if (start <= left && right <= end) {
			return tree[node];
		}
		ll mid = (left + right) / 2;
		return query(node * 2, left, mid , start, end) + query(node*2+1,mid+1,right,start,end);
	}
};

seg s1;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(nullptr);
	cin >> n >> q;
	for (int i = 0; i < q; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			cout << s1.query(1, 1, n, b, c) << '\n';
		}
		else {
			s1.update(1, 1, n, b, c, 1);
		}
	}
}