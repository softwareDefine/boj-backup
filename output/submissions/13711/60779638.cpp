#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

int main()
{
	vector<int> vc;
	vector<int> v1;
	int  v2[100010];
	vector<int> lis;
	int a;
	cin >> a;
	for (int i = 0; i < a; i++) {
		int c;
		cin >> c;
		v1.push_back(c-1);
	}
	for (int i = 0; i < a; i++) {
		int c;
		cin >> c;
		v2[c-1] = i;
	}
	for (int i = 0; i < a; i++) {
		vc.push_back(v2[v1[i]]);
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
			int curser = lower_bound(lis.begin(), lis.end(), vc[i]) - lis.begin();
			lis[curser] = vc[i];
		}
	}
	cout << lis.size();
}