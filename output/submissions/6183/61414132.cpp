#include <iostream>
#include <vector>
#include <string>

using namespace std;
vector<string> str(1010); vector<string> ptr(110);
int n, m; short point[1010];
inline short ctol(char a) {	return a - ((a >= 'a') ? 'a' : 'A');}
int cnt;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {cin >> str[i];}
	for (int i = 0; i < m; i++) {cin >> ptr[i];}
	for (auto &t : str) {
		for (int i = 0;i<m;i++) {
			int pointer = 0;
			int szze = t.size();
			for (int j = 0; j < szze; j++) {if (ctol(t[j]) == ctol(ptr[i][pointer])) {pointer++;}}
			if (pointer==ptr[i].size()) {
				point[cnt]++;
			}
		}
		cnt++;
	}
	for (int i = 0; i < n; i++) {cout << point[i] << '\n';}
}