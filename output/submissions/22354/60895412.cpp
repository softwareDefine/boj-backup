#include <iostream>
#include <vector>

using ll = long long;
using namespace std;

int n;
string str;
int arr[100010];
ll sum1;
vector<pair<char, int>> vc;
vector<int> left;
vector<int> right;

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
				vc.push_back({str[i] ,arr[i]});
			}
		}
		else {
			vc.push_back({ str[i], arr[i] });
		}
	}
	for (int i = 1; i < vc.size()-2;) {
		if (i+2 < vc.size() && vc[i + 1].second > vc[i + 2].second + vc[i].second) {
			sum1 += vc[i + 1].second;
			if (vc[i + 2].second < vc[i].second) {
				swap(vc[i + 2].second, vc[i].second);
			}
			i += 2;
		}
		else {
			sum1 += vc[i].second + vc[i + 2].second;
			if (i + 3 < vc.size() && vc[i + 1].second > vc[i + 3].second) {
				swap(vc[i + 1].second, vc[i + 3].second);
			}
			i += 3;
		}
	}
	cout << sum1;
}