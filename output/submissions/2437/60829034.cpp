#include <iostream>
#include <algorithm>

using namespace std;

int sum;
int n;
int arr[100010];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
    
	if (arr[0] > 1) {
		cout << 1;
	}
	else {
        sum = arr[0];
		for (int i = 1; i < n; i++) {
			if ( arr[i]-sum <= 1) {
                sum += arr[i];
			}
			else {
				cout << sum + 1;
                return 0;
			}
		}
        cout << sum+1;
	}
    return 0;
}