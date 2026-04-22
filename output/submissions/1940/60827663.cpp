#include <iostream>
#include <algorithm>


using ll = long long;
using namespace std;
ll n, m;
int cnt;
ll arr[1000010];
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int i = 0;
	int j = n - 1;
	while (i < j) {
		if (arr[i] + arr[j] == m) {
			cnt++;
			j--;
			i++;
		}
		else if (arr[i] + arr[j] > m) {
			j--;
		}
		else {
			i++;
		}
	}
	cout << cnt;
}