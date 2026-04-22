#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int map[51][51];
int chickencnt;

int ans=99999999;
vector<pair<int, int>> chicken;
vector<pair<int, int>> house;
vector<pair<int, int>> vc;

void go(int index, int last,int m) {
	if (index == m) {
		int result = 0;
		int mmn=99999999;
		for (auto houselist : house) {
			for (auto chiceknlist : vc) {
				int distance = abs(chiceknlist.first - houselist.first) + abs(chiceknlist.second - houselist.second);
				mmn = min(mmn, distance);
			}
			result += mmn;
			mmn = 99999999;
		}
		ans = min(result,ans);
		return;
	}
	for (int i = last; i < chickencnt; i++) {
		vc.push_back({ chicken[i].first,chicken[i].second });
		go(index + 1,i+1, m);
		vc.pop_back();
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				chickencnt++;
				chicken.push_back({ i,j });
			}
			if (map[i][j]==1) {
				house.push_back({ i,j });
			}
		}
	}
	go(0, 0,m);
	cout << ans;
}