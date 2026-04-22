#include <iostream>
#include <stack>
#include <vector>

using ll = long long;
using namespace std;
stack <pair<ll,ll>> st;
ll before;
ll n;
vector<ll> vc;
ll sum;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		ll a;
		cin >> a;
		if (vc.empty()) {
			vc.push_back(a);
			continue;
		}if (a != vc[vc.size() - 1]) {	vc.push_back(a);}
	}
	for (int i = 0; i < vc.size(); i++) {
		if (st.empty()) { st.push({vc[i],vc[i]}); continue; }
		if (st.top().second == vc[i]) {
		}
		else if (st.top().first == vc[i]) {
		}
		else {
			if (st.top().first > vc[i] && st.top().second < vc[i]) {
			}
			else if (st.top().first > vc[i] && st.top().second > vc[i]) {
				sum += st.top().second - vc[i];
			}
			else if (st.top().first < vc[i] && st.top().second < vc[i]) {
				pair<ll,ll> k = st.top();
				st.pop();
				sum += vc[i] - k.first;
				st.push({ vc[i],k.second});
			}
		}
	}
	cout << sum;
}