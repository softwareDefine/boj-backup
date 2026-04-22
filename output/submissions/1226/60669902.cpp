#include <iostream>
#include <algorithm>
#include <vector>

using ll = long long;
using namespace std;

pair<int,int> arr[100010];
vector<int> vc;
int c[100010];
int dp[100010];
int sum;
int mid;
int n;
int mmx;

void  dfs(int all){
	if (all == 0) {
		return;
	}
	vc.push_back(dp[all]);
	dfs(all - c[dp[all]]);
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) { cin >> arr[i].first; c[i] = arr[i].first;
sum += arr[i].first; arr[i].second = i; }
	sort(arr+1, arr + n+1, [&](auto a,auto b) {
		return a.first > b.first;
	});
	dp[0] = -1;
	for (int i = 1; i <= n; i++) {
		for (int j = sum/2; j >= 0; j--) {
			if (dp[j] && !dp[j + arr[i].first]) {
				mmx = max(j + arr[i].first, mmx);
				dp[j+arr[i].first] = arr[i].second;
			}
		}
	}
	cout << '\n';
	dfs(mmx);
	cout << vc.size() << '\n';
	for (int i = vc.size() - 1; i >= 0; i--) {
		cout << vc[i] << ' ';
	}
}