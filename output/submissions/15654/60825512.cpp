#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int a[10];
bool c[2000000];
vector<int> vc;


void go(int index,int n, int m) {
	if (index == m) {
		for (int i = 0; i < m; i++) {
			cout << a[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; i++) { 
		if (c[vc[i]]) continue;
		a[index] = vc[i];
		c[vc[i]] = true;
		go(index + 1, n, m);
		c[vc[i]] = false;
	}
}


int main()
{
	int n; int m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		vc.push_back({ a });
	}
	sort(vc.begin(), vc.end());
	go(0,n, m);
}