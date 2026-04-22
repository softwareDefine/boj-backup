#include <iostream>
#include <queue>

using ll =long long;
using namespace std;

int n,q;
ll chk[1000100];
ll arr[1000100];
ll brr[1000100];
queue<ll> qu;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> chk[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> brr[i];
	}
	for (int i = n-1; i >=0; i--) {
		if (!chk[i]) {
			qu.push(brr[i]);
		}
	}
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < q; i++) {
		if (!qu.empty()) {
			cout << qu.front() << ' ';
			qu.pop();
			qu.push(arr[i]);
		}
		else {
			cout << arr[i];
		}
	}
}