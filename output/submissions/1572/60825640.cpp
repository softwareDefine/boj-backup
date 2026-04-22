#include <iostream>

using ll = long long;
using namespace std;

ll n, k;
ll arr[1 << 22];
ll tree[1 << 22];
ll sum;
const ll mmx = 65535;
ll update(ll node, ll start, ll end, ll val, ll pos) {
	if (start == end && start == pos) {
		if (val == 0) {
			return tree[node] -= 1;
		}
		else {
			return tree[node] += 1;
		}
	}
	if (end < pos || start > pos) {
		return tree[node];
	}
	ll mid = (start + end) / 2;
	return tree[node] = update(node * 2, start, mid, val, pos) + update(node * 2 + 1, mid + 1, end, val, pos);
}

ll query(ll node, ll start, ll end, ll pos) {
	if (start == end) {
		return start;
	}
	ll mid = (start + end) / 2;
	if (pos <= tree[node * 2]) {
		return query(node * 2, start, mid, pos);
	}
	else {
		return query(node * 2 + 1, mid + 1, end, pos - tree[node * 2]);
	}
}

int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < k; i++) {
		update(1, 0, mmx, 1, arr[i]);
	}
	ll mid = (k + 1) / 2;
	for (int i = 0; i < n - k + 1; i++) {
		sum += query(1, 0, mmx, mid);
		update(1, 0, mmx, 0, arr[i]);
		if (i == n - k) {
			break;
		}
		update(1, 0, mmx, 1, arr[i + k]);
	}
	cout << sum;
}