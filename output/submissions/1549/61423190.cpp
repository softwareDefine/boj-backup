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
	//cin.tie(0)->sync_with_stdio(0);
	cin >> n; for (int i = 0; i < n; i++) { tmp = 0; cin >> tmp; sum[i+1] = sum[i] + tmp; }
	for (int j = 0; j <= n; j++) {
		mp.clear();
		for (int i = 1; i+j <= n; i++) {
			mp[sum[i + j] - sum[i - 1]] = i;
		}
		ll bef = -1;
		ll edf = -1;
		for (auto& i : mp) {
			if (bef == -1) {
				bef = i.second;
				edf = i.first;
				continue;
			}
			if (abs(bef - i.second) >= j) {
				if (ans >= i.first - edf) {
					ans = min(ans, i.first - edf);
					ansd = j;
				}
				bef = i.second;
				edf = i.first;
			}
		}
	}
	cout << ansd+1 << '\n';
	cout << ans;
}