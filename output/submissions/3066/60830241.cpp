#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t;

int main()
{
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n =0;
		vector<int> vc;
		vector<int> lis;
		cin >> n;
		for (int j = 0; j < n; j++) {
			int a;
			cin >> a;
			vc.push_back(a);
		}
		for(int j=0;j<n;j++){
			if (lis.size() == 0) {
				lis.push_back(vc[j]);
				continue;
			}
			if (lis.back() < vc[j]) {
				lis.push_back(vc[j]);
			}
			else {
				int curser = lower_bound(lis.begin(), lis.end(), vc[j]) - lis.begin();
				lis[curser] = vc[j];
			}
		}
		cout << lis.size()<< '\n';
	}
}