#include <iostream>
#include <algorithm>


using namespace std;

int n, k;
int arr[100010];
long long sum;
int minussum;

int cmp(int a, int b) {
	return a > b;
}

int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n,cmp);
	for (int i = 0; i < k; i++) {
		sum += arr[i];
		minussum += (i + 1);
	}
	minussum -= k;
	cout << sum - minussum;
}