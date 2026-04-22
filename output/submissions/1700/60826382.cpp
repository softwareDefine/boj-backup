#include <iostream>
#include <vector>

using namespace std;

vector<int> use;
int cnt[101];
int chk[101];
int ans;
int arr[101];
int n, k;

int main()
{
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < k; i++) {
		if (chk[arr[i]]) {
			continue;
		}
		for (int j = 1; j <= 100; j++) { cnt[j] = 0; }
		if (use.size() < n) {
			chk[arr[i]] = 1;
			use.push_back(arr[i]);
			continue;
		}
		for (int j = i; j < k; j++) {
			if (cnt[arr[j]] == 0 && chk[arr[j]] == 1) {
				cnt[arr[j]] = 999999; 
			}
			if (chk[arr[j]] == 1) {
				cnt[arr[j]] = min(j, cnt[arr[j]]);
			}
		}
		int mmx = 0;
		int mmxidx = 0;
		for (int j = 0; j < k; j++){
			if (chk[arr[j]] == 1) {
				if (cnt[arr[j]] == 0 && chk[arr[j]] == 1) { cnt[arr[j]] = 999999;  }
				if (mmx < cnt[arr[j]] && chk[arr[j]]) {
					mmx = cnt[arr[j]];
					mmxidx = arr[j];
				}
			}
		}
		for (int j = 0; j < n; j++) {
			if (mmxidx == use[j]) {
				chk[use[j]] = 0;
				ans++;
				use.erase(use.begin() + j);
				chk[arr[i]] = 1;
				use.push_back(arr[i]);
				break;
			}
		}
	}
	cout << ans;
}