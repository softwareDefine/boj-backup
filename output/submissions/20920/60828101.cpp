#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
int n, m;
map<string, int> mp;
vector<string> vc;
int cmp(string a, string b) {
	if (mp[a] == mp[b]) {
		if (a.length() == b.length()) {
			return a < b;
		}
		return a.length() > b.length();
	}
	return mp[a] > mp[b];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string a;
		cin >> a;
		if (a.length() < m) {
			continue;
		}
		if (mp.find(a) != mp.end()) {
			mp[a]++;
		}
		else {
			mp.insert({ a,1 });
			vc.push_back(a);
		}
	}
	sort(vc.begin(), vc.end(),cmp);
	for (auto ffnd : vc) {
		cout << ffnd << '\n';
	}
}