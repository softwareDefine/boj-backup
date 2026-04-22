#include <iostream>

using namespace std;

int main()
{
	int n,m;
	cin >>n >> m;
	pair<int, int> now = { n,n };
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		if (x >= now.first || y >= now.second) {
			continue;
		}
		if (x*now.second>=y*now.first ) {
			now.first = x;
		}
		else{
			now.second = y;
		}
	}
	cout << now.first * now.second;
}
