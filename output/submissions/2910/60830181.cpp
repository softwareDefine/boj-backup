#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using ll = long long;
using namespace std;

ll n, c;
unordered_map<long long,int> mp;
vector<pair<int, int>> vc;
int first[1000010];
int main()
{
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		if (mp[k] == 0) {
			first[k] = i;
		}
		mp[k]++;
	}
	for (auto i : mp) {
		vc.push_back({ i.first,i.second });
	}
	sort(vc.begin(), vc.end(), [&](auto a, auto b) {
		if (a.second == b.second) return first[a.first] < first[b.first];
		return a.second > b.second;
	});
	for (auto i : vc) {
		for (int j = 0; j < i.second; j++) {
			cout << i.first << ' ';
		}
	}
}