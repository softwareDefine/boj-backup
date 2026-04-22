#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct alpha {
	int st;
	int ed;
	int idx;
}k;

vector<k> vc;
int visited[100000];
int n, m;

int cmp(k a,k b) {
	if (a.st == b.st) {
		return a.ed > b.ed;
	}
	return a.st < b.st;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		if (a < b) {
			vc.push_back({ a,b , i });
			vc.push_back({ a + n,b + n , i });
		}
		else {
			vc.push_back({ a,b + n , i });
		}
	}
	stable_sort(vc.begin(), vc.end(), cmp);
	pair<int, int> all = { 0,-0 };
	for (int i = 0; i < vc.size(); i++) {
		if (visited[vc[i].idx]) {
			continue;
		}
		if (all.first <= vc[i].st && vc[i].ed <= all.second) {
			visited[vc[i].idx] = 1;
			continue;
		}
		all.first = vc[i].st;
		all.second = vc[i].ed;
	}
	for (int i = 0; i < m; i++) {
		if (!visited[i]) {
			cout << i + 1 << " ";
		}
	}
}