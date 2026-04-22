#include <iostream>
#include <vector>

using ll = long long;
using namespace std;

int n, m;
int in[5000000];
int out[5000000];
int money[5000000];
int parent[5000000];
vector<int> vc[5000000];
int cnt;
void dfs(int now) {
	in[now] = ++cnt;
	for (auto& i : vc[now]) {
		dfs(i);
	}
	out[now] = cnt;
}
int tree[1 << 22];
int lazy[1 << 22];
struct seg {
	void update_lazy(int node, int start, int end) {
		if (lazy[node]) {
			tree[node] += (end - start + 1) * lazy[node];
			if (start != end) {
				lazy[node * 2] += lazy[node];
				lazy[node * 2 + 1] += lazy[node];
			}
		}
		lazy[node] = 0;
	}
	ll query(int node, int left, int right, int pos) {
		update_lazy(node, left, right);
		if (pos < left || right < pos) {
			return 0;
		}
		if (left == right) {
			return tree[node];
		}
		ll mid = (left + right) / 2;
		ll first = query(node * 2, left, mid, pos);
		ll second = query(node * 2 + 1, mid + 1, right, pos);
		return first + second;
	}
	void update(int node, int left, int right, int start, int end, ll val) {
		update_lazy(node, left, right);
		if (right < start || end < left) {
			return;
		}
		if (start <= left && right <= end) {
			lazy[node] += val;
			update_lazy(node, left, right);
			return;
		}
		int mid = (left + right) / 2;
		update(node * 2, left, mid, start, end, val);
		update(node * 2 + 1, mid + 1, right, start, end, val);
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}
};

seg s1;
int main()
{
	cin >> n >> m;
	cin >> money[1];
	for (int i = 2; i <= n; i++) {
		cin >> money[i] >> parent[i];
		vc[parent[i]].push_back(i);
	}
	dfs(1);
	for (int i = 0; i < m; i++) {
		char a;
		int b, c;
		cin >> a;
		if (a == 'p') {
			cin >> b >> c;
			s1.update(1, 1, n, in[b]+1, out[b], c);
		}
		else {
			cin >> b;
			cout << s1.query(1, 1, n, in[b])+money[b] << '\n';
		}
	}

}