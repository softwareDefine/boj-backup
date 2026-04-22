#include <iostream>

using ll = long long;

using namespace std;

struct node {

	ll sum;	ll min;

	ll max;

};

node tree[1000010];

struct seg {

	void maketree(int node, int left, int right) {

		if (left == right) {

			tree[node] = { left ,left,left};

			return;

		}

		int mid = (left + right) / 2;

		maketree(node * 2, left, mid);

		maketree(node * 2 + 1, mid + 1, right); 

		tree[node].sum = tree[node * 2].sum + tree[node * 2 + 1].sum;

		tree[node].min = min(tree[node * 2].min, tree[node * 2 + 1].min);

		tree[node].max = max(tree[node * 2].max, tree[node * 2 + 1].max);

	}

	void update(int node, int left, int right,int pos,int val) {

		if (pos < left || pos > right) {

			return;

		}

		if (left == right) {

			tree[node] = { val ,val,val};

			return;

		}

		int mid = (left + right) / 2;

		update(node * 2, left, mid, pos, val);

		update(node * 2 + 1, mid + 1,right, pos, val);

		tree[node].sum = tree[node * 2].sum + tree[node * 2 + 1].sum;

		tree[node].min = min(tree[node * 2].min, tree[node * 2 + 1].min);

		tree[node].max = max(tree[node * 2].max, tree[node * 2 + 1].max);

	}

	node query(int noder, int left, int right, int start, int end) {

		if (right < start || end < left) {

			return {0,10000000000,0};

		}

		if (start <= left && right <= end) {

			return tree[noder];

		}

		int mid = (left + right) / 2;

		node first = query(noder * 2, left, mid, start, end);

		node second = query(noder * 2 + 1, mid + 1, right, start, end);

		return { first.sum + second.sum,min(first.min,second.min),max(first.max,second.max) };

	}

	int find(int node, int left, int right, int pos) {

		if (pos < left || pos > right) {

			return -1;

		}

		if (left == right) {

			return tree[node].sum;

		}

		int mid = (left + right) / 2;

		int first =find(node * 2, left, mid, pos);

		int second = find(node * 2 + 1, mid + 1, right, pos);

		if (first != -1) {

			return first;

		}

		else {

			return second;

		}

	}

};

seg s1;

int t;

int main()

{

	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> t;

	while (t--) {

		for (int i = 0; i < 1000010; i++) {

			tree[i] = { 0,0,0 };

		}

		int n, m;

		cin >> n >> m;

		s1.maketree(1, 0, n - 1);

		for (int i = 0; i < m; i++) {

			int a, b, c;

			cin >> a >> b >> c;

			if (a == 0) {

				int first =s1.find(1, 0, n - 1, b);

				int second = s1.find(1, 0, n - 1, c);

				s1.update(1, 0, n - 1, c, first);

				s1.update(1, 0, n - 1, b, second);

			}

			else {

				ll sum = ll((c - b + 1)) * ll((b + c)) / 2;
				//cout << sum << '\n';
				node a=s1.query(1, 0, n - 1, b, c);
				//cout << a.sum << ' ' << a.min << ' ' << a.max << '\n';
  				if (a.sum == sum && a.min == b && a.max == c) {

					cout << "YES" << '\n';

				}

				else {

					cout << "NO" << '\n';

				}

			}

		}

	}

}