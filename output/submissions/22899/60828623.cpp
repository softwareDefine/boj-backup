#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
int chk[100010];
vector<pair<int, int>> vc;
int n, m;

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		vc.push_back({ 0,a });
	}
	for (int i = 0; i < n; i++) {
		int b;
		cin >> b;
		vc[i].first = b;
	}
	sort(vc.begin(), vc.end());
	for (int i = 1; i <= n; i++) {
		int all = 0;
		long long sum = 0;
		fill(chk, chk + n+1, 0);
		for (int j = 0; j < vc.size(); j++) {
			if (all >= m) {
				break;
			}
			if (chk[vc[j].second] >= i) {
				continue;
			}
			sum += vc[j].first;
			chk[vc[j].second]++;
			all++;
		}
		if (all < m) {
			cout << -1 << ' ';
		}
		else {
			cout << sum << ' ';
		}
	}
}