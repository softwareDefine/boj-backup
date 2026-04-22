#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;
using namespace std;

struct seg {
	ll tree[2000000];
	void udpate(int node, int left, int right, int pos) {
		if (pos > right || left > pos) {
			return;
		}
		if (left == right) {
			tree[node] += 1;
			return;
		}
		int mid = (left + right) / 2;
		udpate(node*2, left, mid, pos);
		udpate(node*2+1, mid + 1, right, pos);
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}
	int query(int node, int left, int right, int start, int end) {
		if (right < start || end < left) {
			return 0;
		}
		if (start <= left && right <= end) {
			return tree[node];
		}
		int mid = (left + right) / 2;
		return query(node * 2, left, mid, start, end) + query(node * 2 + 1, mid + 1, right, start, end);
	}
};

int n;
vector<ll> vc;
vector<ll> arr;
seg s1;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		ll a;
		cin >> a;
		vc.push_back(a);
		arr.push_back(a);
	}
	sort(arr.begin(), arr.end());
	arr.erase(unique(arr.begin(), arr.end()), arr.end());
	for (int i = 0; i < n; i++) {
		int idx = lower_bound(arr.begin(), arr.end(), vc[i]) - arr.begin();
		idx += 1;
		cout << s1.query(1, 1, 500000,idx+1,500000)+1 << '\n';
		s1.udpate(1, 1, 500000, idx);
	}
}