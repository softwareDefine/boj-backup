#include <iostream>
#include <vector>

using namespace std;

int n, m;
int plag;

vector<int> set[210];
int query[1010];
int city[1010];

int find(int now) {
	if (city[now] == now) {
		return now;
	}
	return city[now] = find(city[now]);
}
void merge(int st, int ed) {
	int stp = find(st);
	int edp = find(ed);
	if (stp != edp) {
		if (stp < edp) {
			city[stp] = edp;
		}
		else {
			city[edp] = stp;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		city[i] = i;
	}
	cin >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int temp;
			cin >> temp;
			if (temp == 1) {
				merge(i, j);
			}
		}
	}
	for (int j = 0; j < m; j++) {
		cin >> query[j];
	}
	for (int j = 1; j < m; j++) {
		if (find(query[j] - 1) != find(query[0]-1)) {
			cout << "NO";
			plag = 1;
			break;
		}
	}
	if (plag == 0) {
		cout << "YES";
	}
}
