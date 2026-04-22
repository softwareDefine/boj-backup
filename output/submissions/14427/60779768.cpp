#include <iostream>
#include <math.h>

using namespace std;
int n,m;
pair<long long,long long> tree[ 1<< 18];
int arr[1000010];

pair<long long, long long> maketree(int start, int end, int node) {
	if (start == end) {
		tree[node].first = arr[start];
		tree[node].second = start;
		return { tree[node].first,tree[node].second };
	}
	pair<long long,long long> a = maketree(start, (start + end) / 2, node * 2);
	pair<long long, long long> b = maketree((start + end) / 2 + 1, end, node * 2 + 1);
	if (a.first <= b.first) {
		tree[node].first = a.first;
		tree[node].second = a.second;
	}
	else if (a.first > b.first) {
		tree[node].first = b.first;
		tree[node].second = b.second;
	}
	return {tree[node].first, tree[node].second};
}

void update(int start, int end, int node, int findnode, long long value) {
	if (findnode < start || findnode > end) {
		return;
	}
	if (start == end) {
		tree[node].first = value;
		tree[node].second = start;
		return;
	}
	update(start, (start + end) / 2, node * 2, findnode, value);
	update((start + end) / 2 + 1, end, node * 2 + 1, findnode, value);
	if (tree[node * 2] <= tree[node * 2 + 1]) {
		tree[node].first = tree[node * 2].first;
		tree[node].second = tree[node * 2].second;
	}
	else {
		tree[node].first = tree[node * 2+1].first;
		tree[node].second = tree[node * 2+1].second;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	//int szze = ceil(log2f(n))+1;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	maketree(1, n, 1);
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;
		if (a == 2) {
			cout << tree[1].second << '\n';
		}
		if (a == 1) {
			int st, ed;
			cin >> st >> ed;
			update(1, n, 1, st, ed);
		}
	}
}