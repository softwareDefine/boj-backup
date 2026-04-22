#include <iostream>

using namespace std;

int arr[250010];
int brr[250010];
int n,q;
int wrr[250010];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> brr[i];
	}
	for (int i = 0; i < n; i++) {
		arr[i] = arr[i] - brr[i];
		if (i >= 1) {
			arr[i] = min(arr[i], arr[i - 1]);
		}
	}
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> wrr[i];
	}
	for (int i = 0; i < q; i++) {
		int start = 0;
		int end = n - 1;
		while (start != end) {
			int mid = (start + end + 1) / 2;
			if (arr[mid] >= wrr[i]) {
				start = mid;
			}
			else {
				end = mid - 1;
			}
		}
		if (arr[0] < wrr[0]) {
			cout << 0 << '\n';
		}
		else {
			cout << start + 1 << '\n';
		}
	}
}