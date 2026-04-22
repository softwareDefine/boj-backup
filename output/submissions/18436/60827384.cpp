#include <iostream>

using namespace std;


//pair의 첫번째 : 홀수 , pair의 두 : 짝수
pair<int, int> tree[1 << 18];
pair<int, int> arr[1000000];
int n;
int m;


pair<int,int> maketree(int start, int end, int node) {
	if (start == end) {
		tree[node].first = arr[start].first;
		tree[node].second = arr[start].second;
		return {tree[node].first, tree[node].second};
	}
	pair<int,int> first = maketree(start, (start + end) / 2, node * 2);
	pair<int, int> second = maketree((start + end) / 2 + 1, end, node * 2 + 1);
	tree[node].first = first.first + second.first;
	tree[node].second = first.second + second.second;
	return {tree[node].first,tree[node].second};
}

void update(int start, int end, int node, int newnode, pair<int,int> value) {
	if (newnode < start || newnode > end) {
		return;
	}
	if (start == end) {
		tree[node].first = value.first;
		tree[node].second = value.second;
		return;
	}
	update(start, (start + end) / 2, node * 2, newnode, value);
	update((start + end) / 2+1,end, node * 2+1, newnode, value);
	tree[node].first = tree[node * 2].first + tree[node * 2 + 1].first;
	tree[node].second = tree[node * 2].second + tree[node * 2 + 1].second;
}

pair<int, int> query(int start, int end, int left, int right, int node) {
	if (start > right || left > end) {
		return { 0,0 };
	}
	if (left <= start && end <= right) {
		return { tree[node].first,tree[node].second };
	}
	pair<int, int> first = query(start, (start + end) / 2, left, right, node * 2);
	pair<int, int> second = query((start + end) / 2 + 1, end, left, right, node * 2 + 1);
	return { first.first + second.first,first.second + second.second };
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		if (a % 2 == 0) {
			arr[i].first = 0;
			arr[i].second = 1;
		}
		else {
			arr[i].first = 1;
			arr[i].second = 0;
		}
	}
	maketree(1, n, 1);
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a==1) {
			if (c % 2 == 0) {
				update(1, n, 1, b, { 0,1 });
			}
			else {
				update(1, n, 1, b, { 1,0 });
			}
		}
		else if (a == 2) {
			cout << query(1, n, b,c, 1).second << '\n';
		}
		else {
			cout << query(1, n, b, c, 1).first << '\n';
		}
	}
}