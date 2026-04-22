#include <iostream>

using namespace std;

int n;
int q;
long long arr[100010];
long long tree[1 << 22];

long long maketree(int start, int end, int node) {
	if (start == end) {
		tree[node] = arr[start];
		return tree[node];
	}
	return tree[node] = maketree(start, (start + end) / 2, node * 2) + maketree((start + end) / 2 + 1, end, node * 2 + 1);
}

void update(int start, int end, int idx, long long value, int node) {
	if (idx < start || idx > end) {
		return;
	}
	if (start == end) {
		tree[node] = value;
		return;
	}
	update(start, (start + end) / 2, idx, value, node * 2);
	update((start+end)/2+1, end, idx, value, node * 2+1);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}


long long query(int start, int end, int left, int right, int node) {
	if (start > right || end < left) {
		return 0;
	}
	if (left <= start && end <= right) {
		return tree[node];
	}
	return query(start, (start + end) / 2, left, right, node * 2) + query((start + end) / 2 + 1, end, left, right, node * 2 + 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	maketree(1,n,1);
	for (int i = 0; i < q; i++) {
		long long a=0, b=0, c=0, d=0;
		cin >> a >> b >> c >> d;
		if (a > b) {
			cout << query(1, n, b, a, 1) << '\n';
		}
		else {
			cout << query(1, n, a, b, 1) << '\n';
		}
		update(1, n, c, d, 1);
	}
}
