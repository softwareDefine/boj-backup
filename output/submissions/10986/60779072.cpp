#include <iostream>

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using ll = long long;
using namespace std;


ll n, m;
ll arr[1000010];
ll pre[1000010];
ll getter[1000010];
ll cnt;
int main()
{
	fastio;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	getter[0]++;
	for (int i = 1; i <= n; i++) {
		pre[i] = (arr[i]+pre[i-1])%m;
		getter[pre[i]]++;
	}
	for (int i = 0; i < m; i++) {
		cnt += (getter[i] * (getter[i]-1)) / 2;
	}
	cout << cnt;
}