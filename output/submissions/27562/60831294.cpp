#include <iostream>
#include <vector>

using ll = long long;
using namespace std;

ll cnt = 999999999;

struct p {
	int start;
	int end;
	ll cost;
	int down;
};

struct node {
	ll cost;
	int cow[101];
	int child[2];
	node() {
		cost = 0;
		for (int i = 1; i <= 100; i++) {
			cow[i] = 0;
		}
		child[0] = -1;
		child[1] = -1;
	}
};

int n, m;
vector<node> cow;
vector<p> air;
int root;
ll ans;

int init() {
	node x;
	cow.push_back(x);
	return cow.size() - 1;
}

void search(int node,int idx) {
	if (idx == m) {
		bool flag = 0;
		for (int i = 1; i <= 100; i++) {
			if (cow[node].cow[i]) {
				flag = 1;
			}
		}
		if (!flag) {
			cnt = min(cnt, cow[node].cost);
		}
		return;
	}
	int notuse = init();
	int use = init();
	cow[node].child[0] = notuse;
	cow[node].child[1] = use;
	cow[notuse].cost = cow[node].cost;
	cow[use].cost = cow[node].cost + air[idx].cost;
	for (int i = 1; i <= 100; i++) {
		cow[notuse].cow[i] = cow[node].cow[i];
		cow[use].cow[i] = cow[node].cow[i];
	}
	for (int i = air[idx].start; i <= air[idx].end; i++) {
		cow[use].cow[i] -= air[idx].down;
		cow[use].cow[i] = max(cow[use].cow[i], 0);
	}
	search(notuse, idx + 1);
	search(use, idx + 1);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	root = init();
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int start, end, down;
		cin >> start >> end >> down;
		for (int j = start; j <= end; j++) {
			cow[root].cow[j] += down;
		}
	}
	for (int i = 0; i < m; i++) {
		int start, end, down, cost;
		cin >> start >> end >> down >> cost;
		air.push_back({ start,end,cost,down });
	}
	search(root, 0);
	cout << cnt;
}