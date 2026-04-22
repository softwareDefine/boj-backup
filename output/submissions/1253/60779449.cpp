#include <iostream>
#include <algorithm>

using ll = long long;
using namespace std;

ll arr[1000010];
ll n;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	ll cnt = 0;
	for (int i = 0; i < n; i++) {
		int j = 0;
		int k = n - 1;
		while (j < k) {
			if (j == i) {
				j++;
				continue;
			}
			if (k == i) {
				k--;
				continue;
			}
			if (arr[j] + arr[k] == arr[i]) {
				cnt++;
				break;
			}
			else if(arr[j]+arr[k]> arr[i]) {
				k--;
			}
			else {
				j++;
			}
		}
	}
	cout << cnt;
}