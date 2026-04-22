#include <iostream>
#define inf 100000010
#include <vector>
#include <algorithm>
#include <utility>

using ll = long long;
using namespace std;

int t;
ll dist[501];
vector<pair<int, int>> vc[501];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	cin >> t;
	while (t--) {
		for (int i = 1; i <= 500; i++) {
			vc[i].clear();
		}
		int n, m, w;
		cin >> n >> m >> w;
		for(int i=0;i<m;i++){
			int a, b, c;
			cin >> a >> b >> c;
			vc[a].push_back({b,c});
			vc[b].push_back({ a,c });
		}
		for (int i = 0; i < w; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			vc[a].push_back({ b,-c });
		}
		bool isChange = false;
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					for (auto& k : vc[j]) {
						int end = k.first;
						int cost = k.second;
						if ( dist[end] > dist[j]+cost) {
							dist[end] = dist[j] + cost;
							if (i == n) {
								isChange = true;
							}
						}
					}
					if (isChange) {
						break;
					}
				}
				if (isChange) {
					break;
				}
			}
		if (isChange) {
			cout << "YES" << '\n';
		}
		else {
			cout << "NO" << '\n';
		}
	}
}