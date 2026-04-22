#include <iostream>

using namespace std;

long long n, s;
long long arr[1001000];
long long prefixsum[1001000];
long long ans = 99999999;
int main()
{
	cin >> n >> s;
	if (s == 0) {
		cout << 1;
	}
	else {
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		prefixsum[0] = 0;
		for (int i = 1; i < n + 1; i++) {
			prefixsum[i] = arr[i - 1] + prefixsum[i - 1];
		}
		long long i = 1, j = 0;
		while (i <= n) {
			if(prefixsum[i] - prefixsum[j] >= s) {
				while (prefixsum[i] - prefixsum[j] >= s)
				{
					j++;
				}
				ans = min(ans, i - j+1);
			}
			else if (prefixsum[i] - prefixsum[j] < s) {
				i++;
			}
		}
		if (ans == 99999999) {
			cout << 0;
		}
		else {
			cout << ans;
		}
	}
	
}