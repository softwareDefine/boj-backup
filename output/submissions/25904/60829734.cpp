#include <iostream>

using namespace std;

int n, x;
int query[110];
int arr[110];
int flag = 0;
int main()
{
	cin >> n >> x;
	for (int i = 1; i <= n; i++) {
		cin >> query[i];
	}
	for (int i = 1; i <= n; i++) {
		arr[i] = x + i - 1;
		if (arr[i] > query[i]) {
			cout << i;
			flag = 1;
			break;
		}
	}
	while (!flag) {
		for (int i = 1; i <= n && flag!= 1; i++) {
			arr[i] += n;
			if (arr[i] > query[i]) {
				cout << i;
				flag = 1;
				break;
			}
		}
		if (flag == 1) {
			break;
		}
	}
}