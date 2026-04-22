#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, use, err;
vector<pair<int, int>> vc;

bool check(int mid) {
	int cnt = 0;
	for (int i = 0; i < use; i++) {
		int tcnt = cnt;
		for (int j = tcnt; j < vc.size(); j++) {
			if (vc[j].second > mid) {
				return false;
			}
			if (vc[j].first - vc[tcnt].first < mid) {
				cnt++;
			}
			else {
				break;
			}
		}
	}
	return cnt == err;
}


int main()
{
	cin >> n >> m;
	cin >> use;
	cin >> err;
	for (int i = 0; i < err; i++) {
		int x, y;
		cin >> x >> y;
		vc.push_back({ y,x });
	}
	sort(vc.begin(), vc.end());
	int l =1;
	int r = 1000000;
	while (l < r) {
		int mid = (l + r ) / 2;
		if (check(mid)) {
			r = mid;
		}
		else {
			l = mid+1;
		}
	}
	cout << r;
}