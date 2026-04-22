#include <iostream>

using ll = long long;
using namespace std;

ll n, m;
ll arr[10000010];
ll sum = 0;
ll mmx;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int i = 0;
	int j = 0;
	if (sum < m) {
		sum += arr[0];
	}
	while (i < n  && j < n) {
		if (sum == m) {
			mmx = sum;
			break;
		}
		else if (sum < m) {
			mmx = max(mmx, sum);
			sum += arr[++i]; 
		}
		else {
			sum -= arr[j++];
		}
	}
	cout << mmx;
}