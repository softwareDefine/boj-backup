#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, x;
vector<pair<int, int>> vc[100010];
int dest[100010];
int mmx = -99999999;

int dest3[100010];
int dfs(int start,int go) {
	int dest2[100010];
	for (int i = 1; i <= n; i++) {
		dest2[i] = 99999999;
	}
	priority_queue<pair<int, int>> pq;
	dest2[start] = 0;
	pq.push({ 0 ,start });
	while (!pq.empty()) {
		int now = pq.top().second;
		int val = -pq.top().first;
		pq.pop();
		for (auto nx : vc[now]) {
			int nval = nx.second + val;
			if (nval < dest2[nx.first]) {
				dest2[nx.first] = nval;
				pq.push({ -nval ,nx.first });
			}
		}
	}
	return dest2[go];
}


void bfs(int start) {
	priority_queue<pair<int, int>> pq;
	dest[start] = 0;
	pq.push({ 0 ,start });
	while (!pq.empty()) {
		int now = pq.top().second;
		int val = -pq.top().first;
		pq.pop();
		if (dest[now] < val) {
			continue;
		}
		for (auto nx : vc[now]) {
			int nval = nx.second + val;
			if (nval< dest[nx.first]) {
				dest[nx.first] = nval;
				pq.push({-nval ,nx.first });
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> x;
	for (int i = 1; i <= n; i++) {
		dest[i] = 99999999;
	}
	for (int i = 0; i < m; i++) {
		int st, ed, val;
		cin >> st >> ed >> val;
		vc[st].push_back({ ed,val });
	}
	bfs(x);
	for (int i = 1; i <= n; i++) {
		if (x == i) {
			continue;
		}
		dest3[i] = dfs(i,x);
	}
	for (int i = 1; i <= n; i++) {
		//cout << dest[i] << ' ' << dest3[i] << '\n';
		if (dest3[i] + dest[i] >= 987654321 || dest3[i] + dest[i] < 0)
			continue;
		mmx = max(mmx, dest[i]+dest3[i]);
	}
	cout << mmx;
}