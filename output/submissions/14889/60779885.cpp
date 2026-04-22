#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
int n;
int s[21][21];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> s[i][j];
		}
	}
	int ans = -1;
	for (int i = 0; i < (1 << n); i++) {
		vector<int> first, second;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				first.push_back(j);
			}
			else {
				second.push_back(j);
			}
		}
		if (first.size() != n / 2) {
			first.clear();
			second.clear();
			continue;
		}
		int all1=0, all2=0;
		for (int one = 0; one < n / 2; one++) {
			for (int two = 0; two < n / 2; two++) {
				if (one == two) {
					continue;
				}
				all1 += s[first[one]][first[two]];
				all2 += s[second[one]][second[two]];
			}
		}
		first.clear();
		second.clear();
		int diff = abs(all1 - all2);
		if (ans == -1 || ans > diff) {
			ans = diff;
		}
	}
	cout << ans ;
}