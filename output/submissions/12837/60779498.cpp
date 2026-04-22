#include <iostream>

using namespace std;

int n,m;
long long tree[1 << 22];

/*long long maketree(int start, int end, int node) {
	if (start == end) {
		return tree[node] = arr[start];
	}
}*/

void update(int start, int end, int node, int fidx, long long val) {
	if (fidx <start || fidx > end) {
		return;
	}
	if (start == end) {
		tree[node] += val;
		return;
	} 
	update(start, (start + end) / 2, node * 2, fidx, val);
	update((start + end) / 2 + 1, end, node * 2 + 1, fidx, val);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

long long query(int start, int end, int left, int right, int node) {
	if (right < start || left > end) {
		return 0;
	}
	if (left <= start && end <= right) {
		return tree[node];
	}
	return query(start,(start+end)/2,left,right,node*2) + query((start+end)/2+1,end,left,right,node*2+1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	//maketree(1, n, 1);
	for (int i = 0; i < m; i++) {
		long long a,b,c;
		cin >> a >> b >> c;
		if (a == 1) {
			update(1, n, 1, b, c);
		}
		else if (a == 2) {
			cout << query(1, n, b, c, 1) << '\n';
		}
	}
}