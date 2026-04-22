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
		sum += st.size();
		while (!st.empty() && st.top() < arr[i]) {
			st.pop();
		}
		st.push(arr[i]);
	}
	cout << sum;
}