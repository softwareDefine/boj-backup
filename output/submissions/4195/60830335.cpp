#include <iostream>
#include <string>
#include <unordered_map>
#include <map>

using namespace std;
unordered_map<string, string> mp;
map<string, int> mount;
int n;
int cnt;
string find(string now) {
	if (mp.find(now)->second == now) {
		return now;
	}
	return mp.find(now)->second = find(mp.find(now)->second);
}


void merge(string st,string ed) {
	string stp = find(st);
	string edp = find(ed);
	if (stp != edp) {
		if (mount[stp] < mount[edp]) {
			swap(stp, edp);
		}
		mount[stp] += mount[edp];
		mp[edp] = stp;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int m;
		mp.clear();
		mount.clear();
		cin >> m;
		for (int j = 0; j < m; j++) {
			string a; string b;
			cin >> a >> b;
			if (mp.count(a)==0) {
				mp.insert({ a,a });
				mount.insert({ a,1 });
			}
			if (mp.count(b)==0) {
				mp.insert({ b,b });
				mount.insert({ b,1 });
			}
			merge(a, b);
			int cnt = 0;
			string parent1 = find(a);
			string parent2 = find(b);
			cout << max(mount[parent1],mount[parent2]) << '\n';
		}
	}
}