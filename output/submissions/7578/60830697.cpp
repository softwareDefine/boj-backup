#include <iostream>
#include <algorithm>

using ll = long long;
using namespace std;

ll n;
ll arra[500010];
ll arrb[500010];
ll tree[1 << 22];
ll table[5000000];
const ll mmx = 1000000;
ll sum;
ll update(ll start,ll end,ll node,ll val,ll pos) {
	if (pos < start || pos > end) {
		return tree[node];
	}
	if (start == end) {
		return tree[node] = val;
	}
	ll mid = (start + end) / 2;
	return tree[node] = update(start, mid, node * 2, val, pos) + update(mid + 1, end, node * 2 + 1, val, pos);
}
//query(i+1, n - 1, 0, n - 1, 1);
ll query(ll start,ll end,ll left,ll right,ll node) {
	if (left > end || right < start) {
		return 0;
	}
	if (left >= start && right <= end) {
		return tree[node];
	}
	ll mid = (left + right) / 2;
	return query(start, end, left, mid, node * 2) + query(start, end, mid + 1, right, node * 2 + 1);
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arra[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> arrb[i];
		table[arrb[i]] = i;
		arrb[i] = i;
	}
	for (int i = 0; i < n; i++) {
		arra[i] = table[arra[i]];
	}
	for (int i = 0; i < n; i++) {
		update(0,n-1,1,1,arra[i]);
		sum+= query(arra[i] + 1, n - 1, 0, n - 1, 1);
	}
	cout << sum;
}