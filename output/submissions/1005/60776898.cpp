#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int t;

int n, k, ender;
int arr[100010] = { 0, };
int dp[100010] = { 0, };
vector<int> vc[100010];
int chk[100010];
int flag;
queue<int> qu;

void init() {
	while (!qu.empty()) {
		qu.pop();
	}
	for (int i = 0; i < 100010; i++) {
		chk[i] = 0;
		dp[i] = 0;
		arr[i] = 0;
		vc[i].clear();
	}
	n = 0;
	k = 0;
	ender = 0;
	flag = 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> t;
	while (t--) {
		init();
		cin >> n >> k;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
		}
		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			vc[x].push_back(y);
			chk[y]++;
		}
		cin >> ender; 
		while (1) {
			int cnt = 0;
			for (int i = 1; i <= n; i++) {
				if (chk[i] == 0) {
					qu.push(i);
					chk[i] = -1;
					dp[i] = max(arr[i],dp[i]);
				}
				if (chk[i] == -1) {
					cnt++;
				}
			}
			if (cnt == n) {
				break;
			}
			while (!qu.empty()) {
				int now = qu.front();
				qu.pop();
				for (auto i : vc[now]) {
					dp[i] = max(dp[now] + arr[i], dp[i]);
					chk[i]--;
				}
			}
		}
		cout << dp[ender] << '\n';
	}
}
