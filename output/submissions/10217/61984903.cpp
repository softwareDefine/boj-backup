#include <iostream>
#include <vector>
#include <queue>
#define inf 999999999

using namespace std;

struct node {
	int now;
	int cost;
	int time;
};
class compare {
public:
	bool operator()(node& e1, node& e2) {
		if (e1.time == e2.time) {
			return e1.cost < e2.cost;
		}
		return e1.time > e2.time;
	}
};
// 다음향하는 위치, 비용,시간
vector<node> vc[110];
int dp[110][10010]; // i번째 비용 j 일때 최소 시간
int mmn = inf;
int t, n, m, k;


void daik(int start, int end) {
	// now cost time
	priority_queue<node, vector<node>, compare> pq;
	pq.push({ start,0,0 });
	dp[start][0] = 0;
	while (!pq.empty()) {
		int time = pq.top().time;
		int cost = pq.top().cost;
		int now = pq.top().now;
		pq.pop();
        if(now == n && cost <= m){
            mmn = min(time,mmn);
        }
		if (dp[now][cost] < time) {
			continue;
		}
		for (auto& i : vc[now]) {
			int next = i.now;
			int ncost = i.cost;
			int ntime = i.time;
			if (cost + ncost > m) {
				continue;
			}
			if (dp[next][cost + ncost] > dp[now][cost] + ntime) {
				dp[next][cost + ncost] = dp[now][cost] + ntime;
				pq.push({ next,cost + ncost,(dp[now][cost] + ntime) });
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> t;
	while (t--) {
		for (int i = 0; i < 110; i++) {
			vc[i].clear();
			for (int j = 0; j < 10010; j++) {
				dp[i][j] = inf;
			}
		}
		cin >> n >> m >> k;
		for (int i = 0; i < k; i++) {
			int u, v, c, t;
			cin >> u >> v >> c >> t;
			vc[u].push_back({ v,c,t });
		}
		mmn = inf;
		daik(1, n);
		if (mmn == inf) {
			cout << "Poor KCM" << '\n';
		}
		else {
			cout << mmn << '\n';
		}
	}
}