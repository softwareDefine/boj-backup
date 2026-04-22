#define vc  i.second
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>


using namespace std;

int parent[1000010];
bool chk[1000010];
int n, m;

map<int,vector<pair<pair<int,int>,int>>> mp;
vector<int> 답;

int find(int now) {
	if (parent[now] == now) {
		return now;
	}
	return parent[now] = find(parent[now]);
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

vector<pair<int, int>> ans;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	for (int i = 0; i <= 100000; i++) { parent[i] = i; }
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int start, end, coster;
		cin >> start >> end >> coster;
		mp[coster].push_back({{ start,end },i});
	}
	for (auto &i : mp) {
		ans.clear();
		for (auto& j : vc) {
			if (find(j.first.first) != find(j.first.second)) {
				ans.push_back({ j.first.first,j.first.second });
				답.push_back(j.second);
			}
		}
		for (auto& k : ans) {
			merge(k.first, k.second);
		}
	}
	for (auto& i : 답) {
		chk[i] = true;
	}
	for (int i = 0; i < m; i++) {
		if (chk[i]) {
			cout << "TAK" << '\n';
		}
		else {
			cout << "NIE" << '\n';
		}
	}
}