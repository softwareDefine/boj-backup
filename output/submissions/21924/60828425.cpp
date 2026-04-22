#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>

using namespace std;

int n, m;
int parent[100010];
int depart, arrive;
long long sum;
long long all;
int connected;

typedef struct backpack {
	int st;
	int ed;
	long long value;
}h;

vector<h> vc;

int find2(int now) {
	if (parent[now] == now) {
		return now;
	}
	return parent[now] = find2(parent[now]);
}

void merge(int st, int ed) {
	int stp = find2(st);
	int edp = find2(ed);
	if (stp > edp) {
		parent[edp] = stp;
	}
	else {
		parent[stp] = edp;
	}
}

int sameOrNot(int st, int ed) {
	int stp = find2(st);
	int edp = find2(ed);
	return stp == edp;
}

int main()
{
	cin >> n >> m;
	connected = n;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		long long c;
		cin >> a >> b >> c;
		all += c;
		vc.push_back({ a,b,c });
	}
	stable_sort(vc.begin(), vc.end(), [](h a, h b) {
		return a.value < b.value;
	});
	int szze = vc.size();
	for (int i = 0; i < szze; i++) {
		if (!sameOrNot(vc[i].st, vc[i].ed)) {
			sum += vc[i].value;
			merge(vc[i].st, vc[i].ed);
			connected--;
		}
	}
	if (connected == 1) {

		cout << all - sum;
	}
	else {
		cout << -1;
	}
}