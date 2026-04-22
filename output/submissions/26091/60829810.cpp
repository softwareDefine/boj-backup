#include <iostream>
#include <algorithm>

using ll = long long;
using namespace std;

ll n,k;
ll arr[1000100];
ll cnt;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	ll i = 0;
	ll j = n - 1;
	while (i < j) {
		if (arr[i] + arr[j] >= k) {
			i++;
			j--;
			cnt++;
		}
		else {
			i++;
		}
	}
	cout << cnt;
}