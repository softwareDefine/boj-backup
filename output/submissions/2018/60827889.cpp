#include <iostream>

using ll = long long;
using namespace std;
ll n;
int cnt;
int main()
{
	cin >> n;
	for (int k = 1; k <= n; k++) {
		if (n <= k*(k - 1) / 2) {
			break;
		}
		if ((n - k * (k - 1) / 2) % k ==0) {
			cnt++;
		}
		
	}
	cout << cnt;
}