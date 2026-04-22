#include <iostream>
#include <math.h>

using ll = long long;
using namespace std;

ll t;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		if (n % 3 == 0) {
			cout << n*n*n/27 << '\n';
		}
		else if (n % 4 == 0) {
			cout << n*n*n / 32 << '\n';
		}
		else {
			cout << -1 << '\n';
		}
	}
}