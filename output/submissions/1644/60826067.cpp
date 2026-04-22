#include <iostream>
#include <vector>


using namespace std;
int n;
int fail[4000100];
int cnt;
vector<int> getPar(int n) {
	vector<int> ans;
	for (int i = 2; i <= n; i++) {
		if (fail[i] == 1) {
			continue;
		}
		ans.push_back(i);
		for (int j = i * 2; j <= n; j += i) {
			fail[j] = 1;
		}
	}
	return ans;
}

int main()
{
	cin >> n;
	auto vc = getPar(n);
	if (vc.size() == 0) {
		cout << 0;
	}
	else {
		vc.push_back(0);
		int i = 0;
		int j = 0;
		int sum = 0;
		while (j <= vc.size()-1) {
			if (sum == n) {
				sum += vc[j++];
				cnt++;
			}
			else if (sum < n) {
				sum += vc[j++];
			}
			else if (sum > n) {
				sum -= vc[i++];
			}
		}
		cout << cnt;
	}

}