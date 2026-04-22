#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int n;
int arr[20010];
vector<pair<int,int>> vc;
vector<int> cors;
set<int> st;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		vc.push_back({ x,y });
		cors.push_back(x);
		cors.push_back(y);
	}
	sort(cors.begin(), cors.end());
	cors.erase(unique(cors.begin(), cors.end()), cors.end());
	for (int i = 0; i < n; i++) {
		vc[i].first = lower_bound(cors.begin(), cors.end(), vc[i].first) - cors.begin();
		vc[i].second = lower_bound(cors.begin(), cors.end(), vc[i].second) - cors.begin();
	}
	for (int i = 0; i < n; i++) {
		for (int j = vc[i].first; j<= vc[i].second; j++) {
			arr[j] = i + 1;
		}
	}
	for (int i = 0; i <= 20009; i++) {
		if (arr[i]) {
			st.insert(arr[i]);
		}
	}
	cout << st.size();
}