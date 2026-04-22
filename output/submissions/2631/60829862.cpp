#include <iostream>

using namespace std;

int n;
int arr[100010];
int lis[100010];
int mmx;

int main()
{
	fill(lis, lis + 100010, 1);
	cin >> n;
	for (int i = 1;i <= n;i++) {
		cin >> arr[i];
	}
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j < i;j++) {
			if (arr[i] > arr[j]) {
				lis[i] = max(lis[i], lis[j] + 1);
				mmx = max(lis[i], mmx);
			}
		}
	}
	cout << n - mmx;
}