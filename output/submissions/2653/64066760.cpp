#include <iostream>
#include <map>
#include <set>

using namespace std;

int arr[110][110];
int parent[10010];
int n;
int flag;
int find(int now) {
	if (parent[now] == now) { return now; }
	return parent[now] = find(parent[now]);
}

void merge(int st, int ed) {
	int stp = find(st);
	int edp = find(ed);
	if (stp > edp) {
		parent[stp] = edp;
	}
	else {
		parent[edp] = stp;
	}
}
map<int, set<int>> mp;
int main()
{
	for (int i = 1; i < 10010; i++) {
		parent[i] = i;
	}
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 0 && i != j) {
				merge(i, j);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (arr[i][j] == 0 && find(i) != find(j)) {
				flag = 1;
			}
			if (arr[i][j] == 0) {

				mp[find(i)].insert(j);
			}
			if (arr[i][j] == 1 && find(i) == find(j)) {
				flag = 1;
			}
		}
	}
	for (auto& i : mp) {
		if (i.second.size() == 1) {
			flag = 1;
		}
	}
	if (flag) {
		cout << 0;
	}
	else {
		cout << mp.size() << '\n';
		for (auto& i : mp) {
			for (auto& j : i.second) {
				cout << j << ' ';
			}
			cout << '\n';
		}
	}
}