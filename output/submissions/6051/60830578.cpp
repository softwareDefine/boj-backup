#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> vc[80100];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char a;
		int k;
		cin >> a;
		if (a == 'a') {
			cin >> k;
			if (i==0) {
			}
			else {
				vc[i] = vc[i - 1];
			}
			vc[i].push_back(k);
			cout << vc[i][vc[i].size()-1] << '\n';
		}
		else if (a == 's') {
			if (i == 0) {
				cout << "-1" << '\n';
			}
			else {
			if (vc[i - 1].empty()) {
				cout << "-1" << '\n';
			}
			else {
				vc[i] = vc[i - 1];
				vc[i].pop_back();
				if (vc[i].empty()) {
					cout << -1 << '\n';
				}
				else {
					cout << vc[i][vc[i].size()-1] << '\n';
				}	
			}
			}
			
		}
		else if (a == 't') {
			cin >> k;
			
			if (k == 1) {
			}
			else {
				vc[i] = vc[k - 2];
			}
			if (vc[i].empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << vc[i][vc[i].size()-1] << '\n';
			}
		}
	}
}