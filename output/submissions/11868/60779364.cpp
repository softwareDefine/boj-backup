#include <iostream>
#include <vector>

using namespace std;

int n;
vector<long long> vc;
int ans;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		int v;
		cin >> v;
		vc.push_back(v);
	}
	ans = vc[0];
	for (int i = 1; i < n; i++) {
		ans ^= vc[i];
	}
	if (ans == 0) {
		cout << "cubelover";
	}
	else {
		cout << "koosaga";
	}
}
