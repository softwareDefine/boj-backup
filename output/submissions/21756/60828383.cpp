#include <iostream>
#include <vector>

using namespace std;
int n;
vector<int> vc;
vector<int> vc2;

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		vc.push_back(i);
	}
	if (n == 1) {
		cout << 1;
	}
	else {
		while (1) {
			for (int i = 0; i < vc.size(); i++) {
				if ((i + 1) % 2 == 0) {
					vc2.push_back(vc[i]);
				}
			}
			vc.clear();
			if (vc2.size() == 1) {
				cout << vc2[0];
				break;
			}
			for (int i = 0; i < vc2.size(); i++) {
				if ((i + 1) % 2 == 0) {
					vc.push_back(vc2[i]);
				}
			}
			vc2.clear();
			if (vc.size() == 1) {
				cout << vc[0];
				break;
			}
		}
	}
}