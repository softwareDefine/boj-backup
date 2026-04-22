#include <iostream>
#include <algorithm>

using ll = long long;
using namespace std;

int n;
int arr[100010];
int brr[100010];
ll sum;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> brr[i];
	}
	sort(arr, arr + n, [&](auto a, auto b) {
		return a < b;
	});
	sort(brr, brr + n, [&](auto a, auto b) {
		return a > b;
	});
	for (int i = 0; i < n; i++) {
		sum += arr[i] * brr[i];
	}
	cout << sum;
}