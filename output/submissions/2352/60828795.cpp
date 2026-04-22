// a-197.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<pair<int, int>> vc;
vector<int> lis;
vector<int> ans;
int index[100010];

int cmp(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int b;
		cin >> b;
		vc.push_back({ i+1,b });
	}
	sort(vc.begin(), vc.end(),cmp);
	for (int i = 0; i < n; i++) {
		if (lis.size() == 0) {
			index[i] = 0;
			lis.push_back(vc[i].second);
			continue;
		}
		if (lis.back() < vc[i].second) {
			index[i] = lis.size();
			lis.push_back(vc[i].second);
		}
		else {
			index[i] = lower_bound(lis.begin(), lis.end(), vc[i].second)-lis.begin();
			int curser = lower_bound(lis.begin(), lis.end(), vc[i].second) - lis.begin();
			lis[curser] = vc[i].second;
		}
	}
	cout << lis.size() << '\n';
}