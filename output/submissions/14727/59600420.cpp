#include <iostream>

using ll = long long;
using namespace std;

ll n;
ll tree[1 << 22];
ll arr[1000010];
ll mmx;

ll maketree(ll start,ll end,ll node) {
	if (start == end) {
		return tree[node] = start;
	}
	ll mid = (start + end) / 2;
	ll fd = maketree(start, mid, node * 2);
	ll sd = maketree(mid + 1, end, node * 2 + 1);
	return tree[node] = (arr[fd] < arr[sd])?fd:sd;
}

ll query(ll start,ll end,ll left,ll right,ll node) {
	if (end < left || right < start) {
		return 1000009;
	}
	if (left <= start && end <= right) {
		return tree[node];
	}
	ll mid = (start + end) / 2;
	ll fd = query(start, mid, left, right, node * 2);
	ll sd = query(mid + 1, end, left, right, node * 2 + 1);
	return  (arr[fd] < arr[sd]) ? fd : sd;
}

void dnc(ll start,ll end) {
	if (start>end) {
		return;
	}
	ll idx = query(0,n-1,start,end,1);
	mmx = max((end - start + 1)*arr[idx],mmx);
	dnc(start, idx - 1);
	dnc(idx + 1, end);
}

int main()
{
	cin >> n;
	arr[1000009] = 1000000000;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	maketree(0, n - 1, 1);
	dnc(0, n - 1);
	cout << mmx;
}