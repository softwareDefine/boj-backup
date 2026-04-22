#include <iostream>


using ll = long long;
using namespace std;

ll n;
ll t;
ll tree[1 << 22];
ll candy;

ll update(ll start,ll end,ll pos,ll val,ll node) {
	if (pos < start || end < pos) {
		return tree[node];
	}
	if (start == end) {
		return tree[node] += val;
	}
	ll mid = (start + end) / 2;
	return tree[node] = update(start, mid, pos, val, node * 2) + update(mid + 1, end, pos, val, node * 2 + 1);
}
void qnu(ll start, ll end, ll pos, ll node) {
	if (start == end) {
		candy = start;
		tree[node] -= 1;
		return;
	}
	ll idx = tree[node * 2];
	ll mid = (start + end) / 2;
	if (pos - idx > 0) {
		qnu(mid+1, end, pos - idx,  node * 2 + 1);
	}
	else {
		qnu(start, mid, pos, node * 2);
	}
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while (t--) {
		ll a, b, c;
		cin >> a >> b;
		if (a == 2) {
			cin >> c;
			update(1, 1000000,b , c, 1);
		}
		else {
			qnu(1, 1000000, b, 1);
			cout << candy << '\n';
		}
	}
}