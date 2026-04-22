#include <iostream>
#include <algorithm>

using namespace std;

int arr[100010];
int n;
int i, j;
int sum;
int cnt;

int main()
{
	cin >> n;
	for (int s = 0; s < n; s++) {
		cin >> arr[s];
	}
	sort(arr, arr + n);
	cin >> sum;
	j = n - 1;
	while (i<j) {
		if(arr[i]+arr[j]==sum){
			cnt++;
			i++;
			j--;
		}else if(arr[i]+arr[j]<sum){
			i++;
		}else if(arr[i]+arr[j]>sum) {
			j--;
		}
	}
	cout << cnt;
}