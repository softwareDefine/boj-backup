#include <iostream>

using namespace std;

typedef struct node {
	int left;
	int right;
	int order;
	int depth;
}node;

node a[100001];
int lefter[10001];
int righter[10001];
int cnt[10001];
int order = 0;

void inorder(int node, int depth) {
	if (node == -1) {
		return;
	}
	inorder(a[node].left, depth + 1);
	a[node].order = ++order;
	a[node].depth = depth;
	inorder(a[node].right, depth + 1);
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		a[x].left = y;
		a[x].right = z;
		if (y != -1) {
			cnt[y] += 1;
		}
		if (z != -1) {
			cnt[z] += 1;
		}
	}
	int root = 0;
	for (int i = 1; i <= n; i++) {
		if (cnt[i] == 0) {
			root = i;
			break;
		}
	}
	inorder(root, 1);
	int maxdepth = 0;
	for (int i = 1; i <= n; i++) {
		int depth = a[i].depth;
		int order = a[i].order;
		if (lefter[depth] == 0) {
			lefter[depth] = order;
		}
		else {
			lefter[depth] = min(lefter[depth], order);
		}
		righter[depth] = max(righter[depth], order);
		maxdepth = max(depth, maxdepth);
	}
	int ans = 0;
	int ans_level = 0;
	for (int i = 1; i <= maxdepth; i++) {
		if (ans < righter[i] - lefter[i] + 1) {
			ans = righter[i] - lefter[i] + 1;
			ans_level = i;
		}
	}
	cout << ans_level << " " << ans << '\n';
}