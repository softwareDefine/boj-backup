#include <iostream>
#include <stack>

using ll = long long;
using namespace std;

int n;
stack<pair<ll,ll>> st;
ll arr[500010];
ll before[500010];
ll sum;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		/*if (!st.empty() && st.top().first == arr[i]) {
			ll cnt = st.top().second;
			st.pop();
			sum += before[i-1]+1;
			st.push({ arr[i],cnt + 1 });
		}
		else {*/
			ll cnt = 0;
			while (!st.empty() && st.top().first <= arr[i]) {
				if (st.top().first == arr[i]) {
					cnt+=st.top().second;
				}
				sum += st.top().second;
				before[i] += st.top().second;
				st.pop();
			}
			if (!st.empty() && st.top().first > arr[i]) {
				sum += 1;
				before[i] += 1;
			}
			if (!st.empty() && st.top().first == arr[i]) {
				sum += st.top().second;
				before[i] += st.top().second;
			}
			st.push({ arr[i],cnt+1 });
		//}

		//cout << sum << ' ';
	}
	cout << sum;
}