#include <iostream>
#include <stack>

using ll = long long;
using namespace std;

int n;
stack<ll> st;
ll arr[5000010];
ll sum;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		while (!st.empty() && st.top() < arr[i]) {
			sum++;
			st.pop();
		}
		if (!st.empty()) {
			sum++;
		}
		st.push(arr[i]);
	}
	cout << sum+1;
}