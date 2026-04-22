#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int n, m;

int parent[100010];
vector<pair<int, int>> vc;

map<int,vector<int>> mp;
vector<int> vc2;
vector<int> ver1, ver2;
int chk[100010];

int find(int now) {
	if (parent[now] == now) {return now;} return parent[now] = find(parent[now]);
}

void merge(int st, int ed) {
	int stp = find(st);
	int edp = find(ed);
	if (stp > edp) {
		parent[stp] = edp;
	}
	else {
		parent[edp] = stp;
	}
}


int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int st, ed;
		cin >> st >> ed;
		vc.push_back({st, ed});
	}
	//iota(parent, parent + 100010, 0);
	for (int i = 0; i < 100010; i++) {
		parent[i] = i;
	}
	if (n == 1 || n == 2) {
		cout << "-1";
	}
	else {
		for (int i = 0; i < vc.size();i++) {
			if (find(vc[i].first) != find(vc[i].second)) {
				merge(vc[i].first, vc[i].second);
				vc2.push_back(i);
			}
		}
		for (int i = 1; i <= n; i++) {
			int k = find(i);
		}
		for (int i = 1; i <= n; i++) {
			mp[find(i)].push_back(i);
		}
		if (mp.size() == 2) {
			int chk = find(vc[vc2[0]].first);
			for (auto i : vc2) {
				if (chk == find(vc[i].first)) {
					ver1.push_back(i);
				}
				else {
					ver2.push_back(i);
				}
			}
			if (ver1.size() == ver2.size()) {
				cout << "-1";
			}
			else {
				cout << ver1.size() + 1 << ' ' << ver2.size() + 1 << '\n';
				for (auto& i : mp) {
					if (find(i.first) == find(vc[ver1[0]].first)) {
						for (auto& j : i.second) {
							cout << j << ' ';
						}
						cout << '\n';
						for (auto& j : ver1) {
							cout << j + 1 << ' ';
						}
						cout << '\n';
					}
				}
				for (auto& i : mp) {
					if (find(i.first) != find(vc[ver1[0]].first)) {
						for (auto& j : i.second) {
							cout << j << ' ';
						}
						cout << '\n';
						for (auto& j : ver2) {
							cout << j + 1 << ' ';
						}
						cout << '\n';
					}
				}
			}
		}
		else if(mp.size()> 2) {
			cout << "-1";
		}
		else {
			int endnode = -1;
			int szze = 0;
			for (auto i : vc2) {
				chk[vc[i].first]++;
				chk[vc[i].second]++;
			}
			for (auto &i : mp) {
				szze = i.second.size();
			}
			for (int i = 0; i < 100010; i++) {
				if (chk[i] == 1) {
					endnode = i;
					break;
				}
			}
			if (endnode == -1) {
				cout << "-1";
			}
			else {
				cout << 1 << ' ' << szze-1 << '\n';
				cout << endnode << '\n';
				/*for (auto i : vc2) {
					if (vc[i].first == endnode || vc[i].second == endnode) {
						cout << i + 1;
						cout << '\n';
						break;
					}
				}*/
				for (int i = 1; i <= n; i++) {
					if (i != endnode) {
						cout << i << ' ';
					}
				}
				cout << '\n';
				for (auto i : vc2) {
					if (vc[i].first != endnode && vc[i].second != endnode) {
						cout << i + 1 << ' ';
					}
				}
				cout << '\n';
			}
		}
	}
}