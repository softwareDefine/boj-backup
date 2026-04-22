#include <iostream>
#include <map>

using namespace std;

int mmx;
map<string, int> mp;
int t;

int main()
{
	cin >> t;
	while (t--) {
		mp.clear();
		mmx = 0;
		int a, b, c;
		cin >> a >> b >> c;
		for (int i = 0; i < a; i++) {
			string str;
			cin >> str;
			mp[str.substr(b - c, c)]++;
		}
		for (auto& i : mp) {
			mmx += i.second / 2;
		}
		cout << mmx << '\n';
	}
}