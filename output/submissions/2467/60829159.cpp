#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[100010];

int i, j;
pair<int, int> mmn;

int main()
{
	cin >> n;
	mmn.first = 1000000000;
	mmn.second = 1000000000;
	for (int k = 0; k < n; k++) {
		cin >> arr[k];
	}
	sort(arr, arr + n);
	j = n - 1;
	while (i < j) {
		if (arr[i]+arr[j]==0) {
			mmn.first = arr[i];
			mmn.second = arr[j];
			break;
		}
		else if(arr[i] + arr[j] > 0) {
			if (abs(arr[i] + arr[j]) < abs(mmn.first+mmn.second)) {
				mmn.first = arr[i];
				mmn.second = arr[j];
			}
			j--;
		}else if(arr[i] + arr[j] < 0){
			if (abs(arr[i] + arr[j]) < abs(mmn.first + mmn.second)) {
				mmn.first = arr[i];
				mmn.second = arr[j];
			}
			i++;
		}
	}
	cout << mmn.first << ' ' << mmn.second;
}