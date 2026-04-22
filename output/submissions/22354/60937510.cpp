#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;
using namespace std;

int n;
string str;
int arr[500010];
ll sum1;
vector<pair<char, int>> vc;
int main() {
	cin >> n;
	cin >> str;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (vc.empty()) {
			vc.push_back({ str[i],arr[i] });
		}
		else if (vc[vc.size() - 1].first == str[i]) {
			if (vc[vc.size() - 1].second < arr[i]) {
				vc.pop_back();
				vc.push_back({ str[i] ,arr[i] });
			}
		}
		else {
			vc.push_back({ str[i], arr[i] });
		}
	}
	sort(vc.begin() + 1, vc.end() - 1);
	for (int i = 1; i < vc.size()/2 - vc.size()%2; i++) {
		sum1 += vc[i].second;
	}
	cout << sum1;
}