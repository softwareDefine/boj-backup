#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		vector<int> vc;
		vector<int> lis;
		int a, b;
		cin >> a >> b;
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
		cout << "Case #" << i + 1 << '\n';
		if(lis.size() >= b){
			cout << 1 << '\n';
		}
		else {
			cout << 0 << '\n';
		}
	}
}