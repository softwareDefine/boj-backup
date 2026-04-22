#include <iostream>
#include <string>

using namespace std;

int n;
int b[110][110];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		string a;
		cin >> a;
		if (a.length() >= 6 && a.length() <= 9) {
			cout << "yes" << '\n';
		}
		else {
			cout << "no" << '\n';
		}
	}
}