#include <iostream>
#include <vector>

using namespace std;

long long n, s, d, t, ans;

int main()
{
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> s >> d;
		ans = 0;
		for (int j = 0; j < n; j++) {
			int a, b;
			cin >> a >> b;
			if (s * d >= a) {
				ans += b;
			}
		}
		cout << "Data Set" << " " << i+1 << ":\n" << ans << '\n' << '\n';
	}
}