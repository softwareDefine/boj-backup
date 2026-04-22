#include <iostream>

using ll = long long;
using namespace std;
int n,q;
ll arr[1000010];
ll tree[1 << 22];
ll lazy[1 << 22];

struct seg {
	ll init(int node,int left,int right) {
		if (left == right) {
			return tree[node] = arr[left];
		}
		ll mid = (left + right) / 2;
		return tree[node] = init(node * 2, left, mid) ^ init(node * 2 + 1, mid + 1, right);
	}
	void update_lazy(int node,int left,int right){
		if (lazy[node]) {
			if (left != right) {
				lazy[node * 2] ^= lazy[node];
				lazy[node * 2 + 1] ^= lazy[node];
			}
			if ((right - left + 1) % 2 == 1) {
				tree[node] ^= lazy[node];
			}
		}
		lazy[node] = 0;
	}
	void update(int node,int start,int end,int left,int right,ll val) {
		update_lazy(node, left, right);
		if (end < left || right < start) {
			return;
		}
		if (start <= left && right <= end) {
			if (left != right) {
				lazy[node * 2] ^= val;
				lazy[node * 2 + 1] ^= val;
			}
			if ((right - left + 1) % 2 == 1) {
				tree[node] ^= val;
			}
			return;
		}
		ll mid = (left + right) / 2;
		update(node * 2,start, end, left, mid, val);
		update(node * 2 + 1, start, end, mid + 1, right, val);
		tree[node] = tree[node * 2] ^ tree[node * 2 + 1];
	}
	ll query(int node,int start,int end,int left,int right) {
		update_lazy(node, left, right);
		if (right < start || end < left) {
			return 0;
		}
		if (start <= left && right <= end) {
			return tree[node];
		}
		ll mid = (left + right) / 2;
		return query(node * 2, start, end, left, mid) ^ query(node * 2 + 1, start, end, mid+1, right);
	}
};

seg s1;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	s1.init(1, 0, n - 1);
	cin >> q;
	for (int i = 0; i < q; i++) {
		int a, b, c, d;
		cin >> a;
		if (a == 1) {
			cin >> b >> c >> d;
			s1.update(1, b, c, 0, n - 1, d);
		}
		else {
			cin >> b;
			cout << s1.query(1, b, b, 0, n - 1) << '\n';
		}
	}
}