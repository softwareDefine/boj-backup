#include <iostream>

using namespace std;

string a, b;
int arr[4100][4100];
int mmx = 0;
int main()
{
	cin >> a;
	cin >> b;
	for (int i = 1; i <= a.size(); i++) {
		for (int j = 1; j <= b.size(); j++) {
			if (a[i-1] == b[j-1]) {
				arr[i][j]= arr[i - 1][j - 1]+1;
			}
			else {
			}
		}
	}
	for (int i = 1; i <= a.size(); i++) {
		for (int j = 1; j <= b.size(); j++) {
			mmx = max(arr[i][j],mmx);
		}
	}
	cout << mmx;
}