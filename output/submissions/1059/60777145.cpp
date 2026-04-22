#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[10000];
int finder;
int cnt;
int flag;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cin >> finder;
	sort(arr, arr + n);
	for (int i = 1; i <= 1000; i++) {
		for (int j = i + 1; j <= 1000; j++) {
			for (int k = 0; k < n; k++) {
				if (!(i <= arr[k] && arr[k] <= j)) {
					flag = 0;
				}
				else {
					flag = 1;
					break;
				}
			}
			if ((i <= finder && finder <= j) && flag == 0) {
				cnt++;
				flag = 0;
			}
		}
	}
	cout << cnt;
}