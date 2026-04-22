#include <iostream>
#include <vector>
#include <queue>

using ll = long long;
using namespace std;
int n;
vector<ll> vc[100010];
ll in[100010];
ll dp[100010];
ll cost[1000010];
queue<ll> qu;

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> cost[i];
		dp[i] = cost[i];
		while (1) {
			int a;
			cin >> a;
			if (a == -1) {
				break;
			}
			in[i]++;
			vc[a].push_back(i);
		}
	}		
	for (int j = 1; j <= n; j++) {
		if (in[j] == 0) {
			qu.push(j);
            in[j] = 9999999;
		}
	}
	while(!qu.empty()) {
		int nx = qu.front();
		qu.pop();
		for(auto &j : vc[nx]) {
			dp[j] = max(dp[nx]+cost[j],dp[j]);
			in[j]--;
		}
		for (int j = 1; j <= n; j++) {
			if (in[j] == 0) {
				qu.push(j);
				in[j] = 999999999;
			}
		}
		
	}for (int j = 1; j <= n; j++) {
		cout << dp[j] << '\n';
	}
}