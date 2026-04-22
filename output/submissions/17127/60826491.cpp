#include <iostream>

using namespace std;

int n;
int arr[100100];
int mmx = 0;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int alli = 1, allj = 1, allk = 1;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n-1; k++) {
				int sum = 0;
				int temp = 1;
				for (int z = 0; z < n; z++) {
					temp *= arr[z];
					if (z == i || z == j || z == k || z == n - 1) {
						sum += temp;
						temp = 1;
					}
				}
				mmx = max(sum, mmx);
			}
		}
	}
	cout << mmx;
}