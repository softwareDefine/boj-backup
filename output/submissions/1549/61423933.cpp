#include <iostream>
#include <map>
#include <vector>
#include <set>

using namespace std;
using ll = long long;
ll tmp,n;
vector<ll> vc;
ll sum[10010];
set<ll> st;
map < ll, ll > mp; ll ansd, ans = 99999999999999;
//i번째 위치에서 +j
int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n; for (int i = 0; i < n; i++) { tmp = 0; cin >> tmp; sum[i+1] = sum[i] + tmp; }
	for (int j = 0; j <= n; j++) {
		st.clear();
		for (int i = 1; i+j <= n; i++) {
			if (i - j - 2 >= 0) {
				st.insert(sum[i-1] - sum[i -j- 2]);
			}
			if (!st.empty()) {
				auto it = st.lower_bound(sum[i + j] - sum[i - 1]);
				auto bef = it;
				if (it != st.end()) {
					if (ans >= abs((*it) - (sum[i + j] - sum[i - 1]))) {
						ans = abs((*it) - (sum[i + j] - sum[i - 1]));
						ansd = j;
					}
				}
				if ((--bef) != st.end()) {
					if (ans >= abs((*bef) - (sum[i + j] - sum[i - 1]))) {
						ans = abs((*bef) - (sum[i + j] - sum[i - 1]));
						ansd = j;
					}
				}
			}
		}
	}
	cout << ansd+1 << '\n';
	cout << ans;
}