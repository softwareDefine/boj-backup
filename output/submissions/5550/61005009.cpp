#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;
using namespace std;

int n, k;
int c[100010];
int g;
vector < ll > vc[100010];
ll sumup[2010][2010];

int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		vc[b].push_back(a);
		g = max(g, b);
	}
	for (int i = 1; i <= g; i++) {
		sort(vc[i].begin(), vc[i].end(), [&](auto a, auto b) { return a < b; });
		for (int j = 0; j < vc[i].size()-1; j++) {
			if (j == 0) {
				sumup[i][0] = vc[i][0];
				continue;
			}
			sumup[i][j + 1] = sumup[i][j] + vc[i][j];
			sumup[i][j] += vc[j].size()-1;
		}
	}
}