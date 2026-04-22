#include <iostream>

using ll = long long;
using namespace std;

ll arr[100010];
ll sum;
ll one, two;
int n;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
		two += arr[i] / 2;
	}
	if (sum % 3 == 0 && two >= sum / 3) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
}
