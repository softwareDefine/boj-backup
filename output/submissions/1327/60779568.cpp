#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

using namespace std;
struct node {
	vector<int> arr;
	node() {
		arr.clear();
	}
};

set < vector<int>> st;
vector<node> vc;
int root;
int n, k;

int init() {
	node x;
	vc.push_back(x);
	return vc.size() - 1;
}

int search(int now, int depth) {
	queue<pair<int, int>> qu;
	qu.push({ now,depth });
	while (!qu.empty()) {
		int now = qu.front().first;
		int depth = qu.front().second;
		qu.pop();
		int flag = 0;
		for (int i = 0; i < n - 1; i++) {
			if (vc[now].arr[i] > vc[now].arr[i + 1]) {
				flag = 1;
			}
		}
		if (!flag) {
			return depth;
		}
		for (int i = 0; i < n - k + 1; i++) {
			int next = init();
			vc[next].arr = vc[now].arr;
			reverse(vc[next].arr.begin() + i, vc[next].arr.begin() + i + k);
			if (st.find(vc[next].arr) == st.end()) {
				st.insert(vc[next].arr);
				qu.push({ next,depth + 1 });
			}
		}
	}
	return -1;
}


int main()
{
	root = init();
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		vc[root].arr.push_back({ a });
	}
	st.insert(vc[root].arr);
	cout << search(root, 0);
}
