#include <iostream>
#include <vector>

using namespace std;

vector<int> vc[100010];
int in[100010];
bool chk[100010];

int cnt;
int n, m;


int dfs(int now,int parent) {
	in[now] = ++cnt;
	int ret = in[now];
	int child = 0;
	for (auto& i : vc[now]) {
		if (in[i]) {
			ret = min(ret, in[i]);
			continue;
		}
		child++;
		int prev = dfs(i, now);
		if (parent != -1 && prev >= in[now]) {
			chk[now] = 1;
		}
		ret = min(ret, prev);
	}
	if (parent == -1 && child >=2) {
		chk[now] = 1;
	}
	return ret;
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int start, end;
		cin >> start >> end;
		vc[start].push_back(end);
		vc[end].push_back(start);
	}
	for (int i = 1; i <= n; i++) {
		if (!in[i]) {
			dfs(i, -1);
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (chk[i]) cnt++;
	}
	cout << cnt << '\n';
	for (int i = 1; i <= n; i++) {
		if (chk[i]) cout << i << ' ';
	}
}