#include <bits/stdc++.h>

using ll = long long;
using namespace std;

ll n,q;

class seg {
public:
	ll tree[1 << 24];
	ll arr[1000100];
	pair<ll,ll> lazy[1 << 24];
	void lazy_update(ll start,ll end,ll node){
		if (lazy[node].second || lazy[node].first) {
			tree[node] += lazy[node].first * (end - start + 1) + lazy[node].second * (end - start) * (end - start + 1) / 2;
			ll mid = (start + end) / 2 ;
			if (start != end) {
				lazy[node * 2].first += lazy[node].first;
				lazy[node * 2].second += lazy[node].second;
				lazy[node * 2 + 1].first += lazy[node].first + mid+1-start;
				lazy[node * 2 + 1].second += lazy[node].second;
			}
		lazy[node].first = 0;
		lazy[node].second = 0;
		}
	}
	ll init(ll start, ll end, ll node) {
		if (start == end) {
			return tree[node] = arr[start];
		}
		ll mid = (start + end) / 2;
		return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
	}
	ll update(ll start, ll end, ll left, ll right, ll node) {
		lazy_update(start, end, node);
		if (end < left || right < start) {
			return 0;
		}
		if (left <= start && end <= right) {
			tree[node] += (start-left+1) * (end - start + 1) + (end - start) * (end - start + 1) / 2;
			ll mid = (start + end) / 2;
			if (start != end) {
				lazy[node * 2].first += start-left+1;
				lazy[node * 2].second += 1;
				lazy[node * 2 + 1].first += mid + 1-left+1;
				lazy[node * 2 + 1].second += 1;
			}
			return tree[node];
		}
		ll mid = (start + end) / 2;
		return tree[node] = update(start, mid, left, right, node * 2) +update(mid + 1, end, left, right, node * 2 + 1);
	}
	ll query(ll start, ll end, ll pos, ll node) {
		lazy_update(start, end, node);
		if (end < pos || pos < start) {
			return 0;
		}
		if (start == end) {
			return tree[node];
		}
		ll mid = (start + end) / 2;
		return query(start, mid, pos, node * 2) + query(mid + 1, end, pos, node * 2 + 1);
	}
};

seg s1;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s1.arr[i];
	}
	s1.init(1,n,1);
	cin >> q;
	for (int i = 0; i < q; i++) {
		ll a, b, c;
		cin >> a >> b;
		if (a == 1) {
			cin >> c;
			s1.update(1, n, b, c, 1);
		}
		else {
			cout << s1.query(1, n, b, 1) << '\n';
		}
	}
}