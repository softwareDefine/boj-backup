#include <iostream>
#include <vector>

using ll = long long;
using namespace std;

vector<int> vc[100010];
ll tree[1 << 22];
ll in[1 << 22];
bool visit[100010];
ll out[1 << 22];
ll lazy[1 << 22];
// i번째꺼를 w만큼 서브트리 전체를 업데이트

struct seg {
	void update_lazy(int node, int left, int right) {
		if (lazy[node]) {
			tree[node] += (right - left + 1) * lazy[node];
			if (left != right) {
				lazy[node * 2] += lazy[node];
				lazy[node * 2 + 1] += lazy[node];
			}
			lazy[node] = 0;
		}
	}
	ll query(int node, int left, int right,int pos) {
		update_lazy(node, left, right);
		if (pos < left || right < pos) {
			return 0;
		}
		if (left == right) {
			return tree[node];
		}
		ll mid = (left + right) / 2;
		ll first = query(node * 2, left, mid, pos);
		ll second = query(node * 2 + 1, mid + 1, right,pos);
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
int cnt = 0;
void dfs(int now) {
	visit[now] = 1;
	in[now] = ++cnt;
	for (auto& i : vc[now]) {
		if (!visit[i]) {
			dfs(i);
		}
	}
	out[now]= cnt;
}

int n, m;

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		if (a == -1) { continue; }
		vc[a].push_back(i);
	}
	dfs(1);
	while (m--) {
		int a=0, b=0, c=0;
		cin >> a;
		if (a == 1) {
			cin >> b >> c;
			s1.update(1,1,n,in[b], out[b], c);
		}
		else if (a == 2) {
			cin >> b;
			cout << s1.query(1, 1, n, in[b]) << '\n';
		}
	}
}