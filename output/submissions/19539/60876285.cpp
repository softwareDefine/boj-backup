#include <iostream>
#include <vector>

using ll = long long;
using namespace std;

int 짝수;
int 홀수, n;
ll one, two;
ll arr[1001001];
ll sum = 0;
ll chk;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	for (int i = 0; i < n; i++) {
		if (arr[i] == 1) {
			one++;
		}else if(arr[i]==3){}
		else {
			chk += arr[i];
		}
	}
	if (sum % 3 == 0) {
		if (one) {
			if (one*2 - two < 0) {
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