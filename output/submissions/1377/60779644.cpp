#include <iostream>
#include <algorithm>

using namespace std;
int n;
pair<int,int> g[1000010];
int mmx;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		g[i].first = a;
		g[i].second = i;
	}
	sort(g, g + n);
	for (int i = 0; i < n; i++) {
		mmx = max(mmx,g[i].second-i);
	}
	cout << mmx+1;
}