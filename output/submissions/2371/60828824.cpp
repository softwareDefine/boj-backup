#include <iostream>
#include <vector>
#include <map>
#include <set>

using ll = long long;
using namespace std;
int n;
vector<int> vc;
int cnt[110];
map<int, set<int>>st;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a,idx = 0;
		while (1) {
			cin >> a;
			if (a == -1) {
				break;
			}
			cnt[idx]++;
			st[idx].insert(a);
			idx++;
		}
	}
	for (auto& i : st) {
		if (i.second.size() == cnt[i.first]) {
			cout << i.first + 1;
			break;
		}
	}
}