#include <iostream>

using ll = long long;
using namespace std;

int n,q;
ll lazy[1 << 22];
ll tree[1 << 22];
ll arr[500010];

struct seg {
	ll init(int node, int left, int right) {
		if (left == right) {
			return tree[node] = arr[left];
		}
		ll mid = (left + right) / 2;
		return tree[node] = init(node * 2, left, mid) ^ init(node * 2 + 1, mid + 1, right);
	}
	void update_lazy(int node,int left,int right){
		if (lazy[node]) {
			if ((right - left + 1) % 2) {
				tree[node] ^= lazy[node];
			}
			if (left != right) {
				lazy[node * 2] ^= lazy[node];
				lazy[node * 2 + 1] ^= lazy[node];
			}
			lazy[node] = 0;
		}
	}
	void update(int node, int left, int right, int start, int end, ll k) {
		update_lazy(node, left, right);
		if (right < start || end < left) {
			return;
		}
		if (start <= left && right <= end) {
			if ((right - left + 1) % 2) {
				tree[node] ^= k;
			}
			if (left != right) {
				lazy[node * 2] ^= k;
				lazy[node * 2 + 1] ^= k;
			}
			return;
		}
		ll mid = (left + right) / 2;
		update(node * 2, left, mid, start, end, k);
		update(node * 2 + 1, mid + 1, right, start, end, k);
		tree[node] = tree[node * 2] ^ tree[node * 2+1];
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
		return query(node * 2, left, mid, start, end) ^ query(node * 2 + 1, mid + 1, right, start, end);
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
	s1.init(1, 0, n-1);
	cin >> q;
	for (int i = 0; i < q; i++) {
		ll a, b, c, d;
		cin >> a;
		if (a == 1) {
			cin >> b >> c >> d;
			s1.update(1, 0, n-1, b, c, d);
		}
		else {
			cin >> b >> c;
			cout << s1.query(1, 0, n-1, b, c) << '\n';
		}
	}
}