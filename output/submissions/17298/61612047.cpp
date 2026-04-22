#include <iostream>
#include <stack>
#include <vector>

using ll = long long;
using namespace std;

ll chk[1 << 22];
stack<pair<int,int>> st;
ll n;
ll arr[1<<22];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		if (st.empty()) {
		}
		while (!st.empty() && st.top().first < arr[i]) {
			chk[st.top().second] = arr[i];
			st.pop();
		}
		st.push({ arr[i],i});
	}
	for (int i = 0; i < n; i++) {
		if (chk[i] == 0) {
			cout << -1 << ' ';
		}
		else {
			cout << chk[i] << ' ';
		}
	}
}