#include <iostream>
#include <algorithm>

using namespace std;
int p, n,cnt,sum,arr[10000];
int main()
{
	cin >> p >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	cnt = 0;
	sum = p;
	while (sum < 200 && cnt < n) {
		sum += arr[cnt++];
	}
	cout << cnt;
}