#include <iostream>

using namespace std;

int arr[200010];
int arr2[200010];
int n, m;
int redcnt,greencnt, bluecnt;
int main()
{
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		cin >> arr2[i];
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		char c;
		cin >> a >> b >> c;
		if (c == 'R') {
			redcnt++;
		}
		else if (c == 'G') {
			greencnt++;
		}
		else {
			bluecnt++;
		}
		
	}
	if (redcnt + greencnt / 2 + greencnt % 2 > bluecnt + greencnt / 2) {
			cout << "jhnah917";
		}
		else
			cout << "jhnan917";
}