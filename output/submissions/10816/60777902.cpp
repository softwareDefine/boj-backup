#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<int, int> mp;
int n, q;
vector<int> vc;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (mp.find(a) != mp.end()) {
			mp[a]++;
		}
		else {
			mp.insert({ a,1 });
		}
	}
	cin >> q;
	for (int i = 0; i < q; i++) {
		int a;
		cin >> a;
		if (mp.find(a) != mp.end()) {
			vc.push_back(mp[a]);
		}
		else {
			vc.push_back(0);
		}
	}
	for (int i = 0; i < q; i++) {
		cout << vc[i] << ' ';
	}
}