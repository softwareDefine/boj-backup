#include <iostream>
#include <algorithm>

using ll = long long;
using namespace std;
pair<string,ll> str[1000010];
int n;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str[i].first >> str[i].second;
	}
	sort(str, str + n, [&](auto a, auto b) {
		if (a.second == b.second) {
			for (int i = 0; i < min(a.first.size(), b.first.size()); i++) {
				if (a.first[i] == b.first[i]) {
					continue;
				}
				return a.first[i] < b.first[i];
			}
			return a.first.size() < b.first.size();
		}
		return a.second > b.second;
	});
	cout << str[0].first;
}