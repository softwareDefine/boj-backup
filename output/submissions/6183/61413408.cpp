#include <iostream>
#include <string>

using namespace std;
string str[1010];
string ptr[110];
int n, m;
int point[1010];
int ctol(char a) {
	if (a >= 'a') { return a - 'a'; }
	return a - 'A';
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> str[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> ptr[i];
	}
	for (int t = 0; t < n; t++) {
		for (int s = 0; s < m; s++) {
			int pointer = 0;
			for (int i = 0; i < str[t].size(); i++) {
				if (ctol(str[t][i]) == ctol(ptr[s][pointer])) {
					pointer++;
				}
			}
			if (pointer==ptr[s].size()) {
				point[t]++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << point[i] << '\n';
	}
}