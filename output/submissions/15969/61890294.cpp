#include <iostream>
#include <algorithm>

using namespace std;
int arr[1000010];
int n;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << *max_element(arr, arr + n) - *min_element(arr, arr + n);
}