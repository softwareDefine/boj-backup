#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;
using namespace std;

int n;
string str;
ll arr[500010];
ll sum;
vector<pair<char, ll>> vc;
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
	if (vc.size() >= 3) {
		sort(vc.begin() + 1, vc.end() - 1, [&](auto a, auto b) {
			return a.second > b.second;
		});
		int szze = vc.size();
		//cout << szze / 2 - (szze % 2 == 0) << '\n';
		for (int i = 1; i <= szze / 2 - (szze % 2 == 0); i++) {
			sum += vc[i].second;
		}
	}
	cout << sum;
}