#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;

int n;

vector<int> vc;
int parent[300010];

int find(int now) {
	if (parent[now] == now) {
		return now;
	}
	return parent[now] = find(parent[now]);
}

void merge(int st, int ed) {
	int stp = find(st);
	int edp = find(ed);
	if (stp != edp) {
		if (stp > edp) {
			parent[stp] = edp;
		}
		else {
			parent[edp] = stp;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	for (int i = 1; i <= n - 2; i++) {
		int st, ed;
		cin >> st >> ed;
		merge(st, ed);
	}
	for (int j = 1; j <= n; j++) {
		vc.push_back(find(parent[j]));
	}
	vc.erase(unique(vc.begin(), vc.end()), vc.end());
	int szze = vc.size();
	for (int i = 0; i < 2; i++) {
		cout << vc[i] << ' ';
	}
}