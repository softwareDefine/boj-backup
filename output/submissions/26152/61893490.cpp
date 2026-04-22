#include <iostream>

using namespace std;

int arr[250010];
int brr[250010];
int n,q;
int wrr[250010];

int main()
{
	arr[0] = 9999999999;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> brr[i];
	}
	for (int i = 1; i <= n; i++) {
		arr[i] = arr[i] - brr[i];
		arr[i] = min(arr[i], arr[i - 1]);
	}
	cin >> q;
	for (int i = 1; i <= q; i++) {
		cin >> wrr[i];
	}
	for (int i = 1; i <= q; i++) {
		int start = 1;
		int end = n;
		while (start != end) {
			int mid = (start + end + 1) / 2;
			if (arr[mid] >= wrr[i]) {
				start = mid;
			}
			else {
				end = mid - 1;
			}
		}
		if (arr[1] < wrr[i]) {
			cout << 0 << '\n';
		}
		else {
			cout << start<< '\n';
		}
	}
}