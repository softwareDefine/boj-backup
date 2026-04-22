#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, k;
vector<int> vc;
int arr[1000010];

int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	if (k >= n) {
		cout << n;
	}
	else {
		for (int i = 0; i < n-1; i++) {
			vc.push_back(arr[i + 1] - arr[i]-1);
		}
		sort(vc.rbegin(), vc.rend());
		int sum = arr[n - 1] - arr[0] + 1;
		for (int i = 0; i < k-1; i++) {
			sum -= vc[i];
		}
		cout << sum << '\n';
	}
}