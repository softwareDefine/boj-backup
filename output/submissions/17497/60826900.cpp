#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long n;
vector<char> ans;
int main()
{
	cin >> n;
	if (n & 1) {
		n *= 2;
		ans.push_back('/');
	}
	while (n) {
		if (n & 2) {
			n -= 2;
			ans.push_back('+');
		}
		if (!n) {
			break;
		}
		n /= 2;
		ans.push_back('*');
	}
	cout << ans.size() << '\n';
	for (int i = ans.size() - 1; i >= 0; i--) {
		cout <<'[' << ans[i]<<']' << ' ';
	}
}