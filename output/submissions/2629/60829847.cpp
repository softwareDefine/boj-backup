#include <iostream>

using namespace std;

bool dp[31][1200010];
bool visit[31][1200010];
int cost[31];
int n,q;

void go(int now, int all) {
	if (now > n) {
		return;
	}
	if (visit[now][all]) {
		return;
	}
	visit[now][all] = 1;
	if (all > 0) {
		dp[now][all] = 1;
	}
	go(now + 1, all);
	go(now + 1, all - cost[now]);
	go(now + 1, all + cost[now]);
	return ;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> cost[i];
	}
	cin >> q;
	go(0, 0);
	for (int i = 0; i < q; i++) {
		int a;
		cin >> a;
		int chk = dp[n][a];
		if (chk == 1) {
			cout << 'Y' << ' ';
		}
		else {
			cout << "N" << ' ';
		}
	}
}