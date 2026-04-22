#include <iostream>

using namespace std;

int mmp[10001000];
int arr[10001000];
int n, m;

int check(int mid) {
	for (int i = 0; i < m; i++) {
		int one = (arr[i] - mid <= 0) ? 0 : arr[i] - mid;
		int two =  arr[i] + mid+1;
		mmp[one] = 1;
		mmp[two] = -1;
	}
	int status = 0;
	for (int i = 0; i < n; i++) {
		status += mmp[i];
		if (status <=0) {
			return 0;
		}
		mmp[i] = 0;
	}
	return 1;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> arr[i];
	}
	int left = 1;
	int right = n;
	while (left < right) {
		int mid = (left + right) / 2;
		if (check(mid)) {
			right = mid;
		}
		else {
			left = mid+1;
		}
	}
	cout << left;
}