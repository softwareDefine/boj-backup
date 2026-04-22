#include <iostream>
#include <vector>

using ll = long long;
using namespace std;

int n;
int one, two;
int arr[1001001];
ll sum = 0;
vector<int> nnw;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	for (int i = 0; i < n; i++) {
		arr[i] %= 3;
		if (arr[i] == 1) {
			one++;
		}
		else {
			two++;
		}
	}
	if (sum % 3 == 0) {
		if (one) {
			if (one > two) {
				cout << "NO";
			}
			else {
				cout << "YES";
			}
			return 0;
		}
		cout << "YES";
	}
	else {
		cout << "NO";
	}
}