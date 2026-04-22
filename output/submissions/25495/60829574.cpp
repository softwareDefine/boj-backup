#include <iostream>
#include <algorithm>

using namespace std;
int p, n,sum,arr[10000],cnt;
int battery;
int main()
{
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	battery = 2;
	sum = 2;
	for (int i = 1; i < n; i++) {
		if (sum >= 100) {
			battery = 2;
			sum = 2;
			continue;
		}
		if (arr[i - 1] == arr[i]) {
			battery *= 2;
			sum += battery;
		}
		else {
			battery = 2;
			sum += battery;
		}
		if (sum >= 100 && i == n-1) {
			battery = 2;
			sum = 0;
		}
	}
	cout << sum;
}