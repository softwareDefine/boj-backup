#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <algorithm>

using namespace std;
set<string> st;
map<string, int> mp;
int n, m;

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		mp.insert({s,0});
	}
	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		if (mp.find(s) != mp.end()) {
			st.insert(s);
		}
		else {
			mp.insert({ s,0 });
		}
	}
	cout << st.size() << '\n';
	for (auto i : st) {
		cout << i << '\n';
	}
}