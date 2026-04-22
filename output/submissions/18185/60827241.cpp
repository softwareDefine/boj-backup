#include <iostream>
#include <vector>

using namespace std;
int money;
int n;
vector<int> vc;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		vc.push_back(a);
	}
	for (int i = 0; i < n; i++) {
		while (vc[i]) {
			if (i + 2 < n && vc[i] > 0 && vc[i + 1] > 0 && vc[i + 2] > 0 && vc[i + 1] <= vc[i + 2]) {
				vc[i]--;
				vc[i + 1]--;
				vc[i + 2]--;
				money += 7;
				continue;
			}
			if (i + 1 < n && vc[i] > 0 && vc[i + 1] > 0) {
				vc[i]--;
				vc[i + 1]--;
				money += 5;
				continue;
			}
			if (i < n && vc[i] > 0) {
				vc[i]--;
				money += 3;
				continue;
			}
		}
		
	}
	cout << money;
}