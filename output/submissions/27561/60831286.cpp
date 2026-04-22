#include <iostream>

using ll = long long;
using namespace std;

int n;
string str;
ll range[1000010];
ll pre[1000010][2];
ll leader[1000010][2]; ll leader2[1000010][2];
int cnt;
ll h, g;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	cin >> str;
	for (int i = 0; i < n; i++) {
		cin >> range[i];
		range[i] -= 1;
	}
	for (int i = 0; i < n; i++) {
		if (str[i] == 'H') {
			pre[i][0] = ((i - 1 < 0) ? 0 : pre[i - 1][0] )+ 1;
			pre[i][1] = (i - 1 < 0) ? 0 : pre[i - 1][1];
			h++;
		}
		else {
			pre[i][1] = ((i - 1 < 0) ? 0 : pre[i - 1][1]) + 1;
			pre[i][0] = (i - 1 < 0) ? 0 : pre[i - 1][0];
			g++;
		}
	}
	for (int i = 0; i < n; i++) {
		if (str[i] == 'H') {
			if (pre[range[i]][0] - ((i - 1 < 0) ? 0 : pre[i-1][0]) == h) {
				leader[i][0]=1;
				leader2[i][0]++;
			}
		}
		else {
			if (pre[range[i]][1] - ((i - 1 < 0) ? 0 : pre[i - 1][1]) == g) {
				leader[i][1] = 1;
				leader2[i][1]++;
			}
		}
		leader2[i][0] = ((i - 1 < 0) ? 0 : leader2[i - 1][0]) + leader2[i][0];
		leader2[i][1] = ((i - 1 < 0) ? 0 : leader2[i - 1][1]) + leader2[i][1];
	}
	for (int i = 0; i < n; i++) {
		if (str[i] == 'H') {
			if (leader2[range[i]][1] - leader2[i][1]>0) {
				leader[i][0] = 1;
			}
		}
		else {
			if (leader2[range[i]][0] -leader2[i][0]> 0) {
				leader[i][1] = 1;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		leader2[i][0] = leader[i][0] + ((i - 1 < 0) ? 0 : leader2[i - 1][0]);
		leader2[i][1] = leader[i][1] + ((i - 1 < 0) ? 0 : leader2[i - 1][1]);
	}
	for (int i = 0; i < n; i++) {
		if (str[i] == 'H' ) {
			if (leader[i][0] == 1) {
				cnt += leader2[n - 1][1] - leader2[i][1];
			}
		}
		else {
			if (leader[i][1] == 1) {
				cnt += leader2[n - 1][0] - leader2[i][0];
			}
		}
	}
	cout << cnt;
}