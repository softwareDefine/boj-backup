#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> vc;
int c[100010];
int a[10];

void go(int index,int start, int n, int m) {
	if (index == m) {
		for (int j = 0; j < m; j++) {
			cout << a[j] << ' ';
		}
		cout << '\n';
		return;
	}
	int checker = 0;
	for (int i = start; i < n; i++) {
		if (vc[i] != checker) {
			a[index] = vc[i];
			checker = a[index];
			go(index + 1,i, n, m);
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
	sort(vc.begin(), vc.end());
	go(0,0, n, m);
}
