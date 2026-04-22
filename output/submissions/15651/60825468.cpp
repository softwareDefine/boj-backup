#include <iostream>

using namespace std;

int a[10];

void go(int index,int n, int m) {
	if (index == m) {
		for (int i = 0; i < m; i++) {
			cout << a[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++) { 
		a[index] = i;
		go(index + 1, n, m);
	}
}


int main()
{
	int n; int m;
	cin >> n >> m;
	go(0,n, m);
}