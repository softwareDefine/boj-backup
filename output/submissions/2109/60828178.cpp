#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using ll = long long;
using namespace std;

int mmd;
class comp {
public:
	bool operator()( pair<int,int> a , pair<int,int> b) {
		return a.first < b.first;
	}
};

ll sum;
int n;
priority_queue<pair<int, int>,vector<pair<int, int>>,comp> pq;
int arr[100010];
int cnt;
vector<pair<int, int>> vc;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> b >> a;
		vc.push_back({ a,b });
	}
	sort(vc.begin(), vc.end(), [&](auto a, auto b) {
		if (a.second == b.second) {
			return a.first < b.first;
		}
		return a.second > b.second;
	});
	for (auto &i : vc) {
		int k = i.first;
		while (arr[k] && k >= 1) {
			k--;
		}
		if (k >= 1) {
			arr[k] = i.second;
			mmd = max(mmd, k);
		}
	}
	for (int i = 1; i <= mmd; i++) { sum += arr[i]; }
	cout << sum;
}