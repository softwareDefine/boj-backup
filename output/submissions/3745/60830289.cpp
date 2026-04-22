// a-204.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int t;int n;
int main()
{
	while (cin >> n) {
		vector<int> lis;
		vector<int> vc;
		
		for (int j = 0; j < n; j++) {
			int a;
			cin >> a;
			vc.push_back(a);
		}
		for (int j = 0; j < n; j++) {
			if (lis.empty()) {
				lis.push_back(vc[j]);
				continue;
			}
			if (lis.back() < vc[j]) {
				lis.push_back(vc[j]);
			}
			else {
				int curser = lower_bound(lis.begin(), lis.end(), vc[j])-lis.begin();
				lis[curser] = vc[j];
			}
		}
		cout << lis.size() << '\n';
	}
}