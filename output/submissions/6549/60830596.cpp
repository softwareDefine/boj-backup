#include <iostream>
#define LLONG_MAX 9223372036854775807
using ll = long long;
using namespace std;
ll tree[1 << 22];
ll arr[100010];
ll mmx;
ll n;
ll maketree(ll start,ll end,ll node) {
	if (start == end) {
		return tree[node] = start;
	}
	ll mid = (start + end) / 2;
	ll fd = maketree(start, mid, node * 2);
	ll sd = maketree(mid + 1, end, node * 2 + 1);
	return tree[node] = (arr[fd] < arr[sd]) ? fd : sd;
}

ll query(ll start, ll end, ll left, ll right, ll node) {
	if (start > right || left > end) {
		return 100008;
	}
	if (left <= start && end <= right) {
		return tree[node];
	}
	ll mid = (start + end) / 2;
	ll fd = query(start, mid, left, right, node * 2);
	ll sd = query(mid + 1, end, left, right, node * 2 + 1);
	return (arr[fd] < arr[sd]) ? fd : sd;
}

void DnC(ll l, ll r) {
	if (r < l) {return;}
	ll idx = query(0, n - 1, l, r, 1);
	mmx = max(mmx,(r - l + 1) * arr[idx]);
	DnC(l, idx -1);
	DnC(idx + 1, r);
}

void init() {
	for (int i = 1; i <= 4 * n + 1; i++) {
		tree[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		arr[i] = 0;
	}
	arr[100008] = LLONG_MAX;
	mmx = 0;
	n = 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while (1) {
		init();
		cin >> n;
		if (n == 0) break;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		maketree(0, n - 1, 1);
		DnC(0, n - 1);
		cout << mmx << '\n';
	}
}