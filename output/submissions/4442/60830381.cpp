#include <iostream>
#include <map>

using ll = long long;
using namespace std;

string stra[100010];
string strb[100010];
map <string, ll> mp;
ll arra[100010];
ll arrb[100010];
ll tree[1 << 22];

ll update(ll start,ll end,ll val,ll pos,ll node) {
	if (pos < start || pos > end) {
		return tree[node];
	}
	if (start == end) {
		return tree[node] = val;
	}
	ll mid = (start + end) / 2;
	return tree[node] = update(start, mid, val, pos, node * 2) + update(mid + 1, end, val, pos, node * 2 + 1);
}

ll query(ll start, ll end, ll left, ll right, ll node) {
	if (start > right || end < left) {
		return 0;
	}
	if (left <= start && end <= right) {
		return tree[node];
	}
	ll mid = (start + end) / 2;
	return query(start, mid, left, right, node * 2) + query(mid + 1, end, left, right, node * 2 + 1);
}

void init() {
	for (int i = 0; i < 100010;i++) {
		arra[i] = 0;
		arrb[i] = 0;
		stra[i] = "";
		strb[i] = "";
	}
	for (int j = 0; j < (1 << 22); j++) {
		tree[j] = 0;
	}
	mp.clear();
}
int main()
{
	while (1) {
		ll n = 0;
		ll sum = 0;
		cin >> n;
		if (n == 0) { break; }
		init();
		for (int i = 0; i < n; i++) {
			 cin >> stra[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> strb[i];
		}
		for (int i = 0; i < n; i++) {
			mp.insert({ stra[i],i });
		}
		for (int i = 0; i < n; i++) {
			arrb[i] = mp[strb[i]];
		}
		for (int i = 0; i < n; i++) {
			arra[arrb[i]] = i;
		}
		for (int i = 0; i < n; i++) {
			update(0, n - 1, 1, arrb[i], 1);
			sum += query(0, n - 1,arrb[i] + 1, n - 1, 1);
		}
		cout << sum << '\n';
 	}
}