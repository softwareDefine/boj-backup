#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#include <iostream>

using ll = long long;
using namespace std;

int n;
ll arr[1001000];
ll arrb[1010000];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		arrb[i] = arr[i];
	}
	ll ptr = 0;
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 == 0) {
			swap(arr[i], arr[ptr]);
			sum += i - ptr;
			ptr++;
		}
	}
	ll ptr2 = 0;
	ll sum2 = 0;
	for (int i = 0; i < n; i++) {
		if (arrb[i] % 2 == 1) {
			swap(arrb[i], arrb[ptr2]);
			sum2 += i - ptr2;
			ptr2++;
		}
	}
	cout << min(sum, sum2);
}
