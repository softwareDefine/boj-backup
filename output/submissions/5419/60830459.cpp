#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;
using namespace std;

int t;
int n;
ll tree[1 << 22];
ll sum;
vector<pair<ll, ll>> vc;
vector<ll> coor;

ll update(ll start, ll end, ll idx, ll node) {
	if (idx < start || idx > end) {
		return tree[node];
	}
	if (start == end) {
		return tree[node] += 1;
	}
	ll mid = (start + end) / 2;
	return tree[node] = update(start, mid, idx, node * 2) + update(mid + 1, end, idx, node * 2 + 1);
}

ll query(ll start, ll end, ll left, ll right, ll node) {
	if (end < left || right < start) {
		return 0;
	}
	if (left <= start && end <= right) {
		return tree[node];
	}
	ll mid = (start + end) / 2;
	return query(start, mid, left, right, node * 2) + query(mid + 1, end, left, right, node * 2 + 1);
}


void init() {
	vc.clear();
	coor.clear();
	sum = 0;
	ll szze = 1 << 22;
	for (int i = 0; i < szze; i++) {
		tree[i] = 0;
	}
	n = 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> t;
	while (t--) {
		init();
		cin >> n;
		for (int i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
			vc.push_back({ x,y });
			coor.push_back(y);
		}
		coor.erase(unique(coor.begin(), coor.end()), coor.end());
		sort(coor.begin(), coor.end());
		for (int i = 0; i < n; i++) {
			vc[i].second = lower_bound(coor.begin(), coor.end(), vc[i].second) - coor.begin();
		}
		sort(vc.begin(), vc.end(), [&](auto a, auto b) {
			if (a.first == b.first) {
				return a.second > b.second;
			}
			return a.first < b.first;
		});
		for (int i = 0; i < n; i++) {
			sum += query(0, 750100, vc[i].second, 750100, 1);
			update(0, 750100, vc[i].second, 1);
		}
		cout << sum << '\n';
	}
}