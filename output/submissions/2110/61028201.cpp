#include <iostream>
#include <algorithm>

using namespace std;

int n, c;
int ans;
long long arr[200010];

int check(int d) {
	int cnt = 1, last = arr[0];
	for (int i = 1; i < n; i++) {
		if(arr[i]-last >= d){
			cnt++;
			last = arr[i];
		}
	}
	return cnt >= c;
}

int main()
{
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int l = 1;
	int r = 1000000000;
	
	while (l <= r) {
		int mid = (l + r) / 2;
		if (check(mid)) {
			ans = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	cout << ans;
}