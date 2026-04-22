#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

int main()
{
		vector<int> vc;
		vector<int> lis;
		int a;
		cin >> a;
		for (int i = 0; i < a; i++) {
			int c;
			cin >> c;
			vc.push_back(c);
		}
		for (int i = 0; i < a; i++) {
			if (lis.size() == 0) {
				lis.push_back(vc[i]);
				continue;
			}
			if (lis.back() < vc[i]) {
				lis.push_back(vc[i]);
			}
			else {
				int curser = lower_bound(lis.begin(), lis.end(), vc[i])-lis.begin();
				lis[curser] = vc[i];
			}
		}
		cout << a- lis.size();
}