#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> vc;
int c[100010];
int a[10];

void go(int index, int n, int m) {
	if (index == m) {
		for (int j = 0; j < m; j++) {
			cout << a[j] << ' ';
		}
		cout << '\n';
		return;
	}
	int checker=0;
	for (int i = 0; i < n; i++) {
		if (!c[i] && vc[i] != checker) {
			a[index] = vc[i];
			checker = a[index];
			c[i]= 1;
			go(index+1, n, m);
			c[i] = 0;
		}
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		vc.push_back(a);
	}
	//vc.erase(unique(vc.begin(), vc.end()), vc.end());
	sort(vc.begin(), vc.end());
	go(0, n, m);
}
