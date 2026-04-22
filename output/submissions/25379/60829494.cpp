#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#include <iostream>

using namespace std;

int n;
int arr[1000010];
int arrb[1000010];

int main()
{
    fastio;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		arrb[i] = arr[i];
	}
	int ptr = 0;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 == 0) {
			swap(arr[i], arr[ptr]);
			sum += i - ptr;
			ptr++;
		}
	}
	int ptr2 = 0;
	int sum2 = 0;
	for (int i = 0; i < n; i++) {
		if (arrb[i] % 2 == 1) {
			swap(arrb[i], arrb[ptr2]);
			sum2 += i - ptr2;
			ptr2++;
		}
	}
	cout << min(sum, sum2);
}
