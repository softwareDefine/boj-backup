#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vc;
vector<int> lis;
int n;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		vc.push_back(a);
	}
	for (int i = 0; i < n; i++) {
		if (lis.size() == 0) {
			lis.push_back(vc[i]);
			continue;
		}
		if (lis.back() < vc[i]) {
			lis.push_back(vc[i]);
		}
		else {
			int curser = lower_bound(lis.begin(), lis.end(), vc[i]) - lis.begin();
			lis[curser] = vc[i];
		}
	}
	cout << n-lis.size();
}