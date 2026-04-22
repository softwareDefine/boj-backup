// a-453.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <set>

using ll = long long;
using namespace std;

ll n, m, k;
ll arr[1000010];
ll parent[1000010];
set<int> st;
long long sum;

int find(int now) {
	if (now == parent[now]) { return now; }
	return parent[now] = find(parent[now]);
}

void merge(int st, int ed) {
	int stp = find(st);
	int edp = find(ed);
		if (arr[stp] > arr[edp]) {
			parent[stp] = edp;
		}
		else {
			parent[edp] = stp;
		}
}

int main()
{
	for (int i = 0; i <= 1000000; i++) { parent[i] = i; }
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) { cin >> arr[i]; }
	for (int i = 0; i < m; i++) {
		ll v, w;
		cin >> v >> w;
		if (find(v) != find(w)) {
			merge(v, w);
		}
	}
	for (int i = 1; i <= n; i++) {
		st.insert(find(i));
	}
	for (auto& i : st) {
		sum += arr[i];
	}
	if (sum > k) {
		cout << "Oh no";
	}
	else {
		cout << sum;
	}
}