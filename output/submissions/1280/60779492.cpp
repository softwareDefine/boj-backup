#include <iostream>

using ll = long long;
using namespace std;

ll arr[200010];
ll sum = 1;
int n;

struct seg {
	pair<ll, ll> tree[800010];
	void update(int node, int left, int right, int pos) {
		if (pos < left || right < pos) {
			return;
		}
		if (left == right) {
			tree[node].second++;
			tree[node].first = left*tree[node].second;
			return;
		}
		int mid = (left + right) / 2;
		update(node * 2, left, mid, pos);
		update(node * 2 + 1, mid + 1, right, pos);
		tree[node].first = tree[node * 2].first + tree[node * 2 + 1].first;
		tree[node].second = tree[node * 2].second + tree[node * 2 + 1].second;
	}
	pair<ll,ll> query(int node, int left, int right, int start, int end) {
		if (right < start || end < left) {
			return { 0,0 };
		}
		if (start <= left && right <= end) {
			return tree[node];
		}
		int mid = (left + right) / 2;
		pair<ll, ll> a = query(node * 2, left, mid, start, end);
		pair<ll, ll> b = query(node * 2 + 1, mid + 1, right, start, end);
		return { a.first + b.first,a.second + b.second };
	}
};

seg s1;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		ll minsum = 0;
		pair<ll, ll> a = s1.query(1, 0, 200000, 0, arr[i] - 1);
		pair<ll, ll> b = s1.query(1, 0, 200000, arr[i] + 1, 200000);
		//cout <<arr[i]<< ' ' << a.first << ' ' << a.second << '\n';
		minsum = arr[i] * a.second - a.first;
		minsum += b.first - arr[i] * b.second;
		if (i == 0) {s1.update(1, 0, 200000, arr[i]); continue; }
		//cout << "1: " << minsum << '\n';
		sum *= minsum%1000000007; s1.update(1, 0, 200000, arr[i]);
		sum %= 1000000007;
	}
	cout << sum;
}