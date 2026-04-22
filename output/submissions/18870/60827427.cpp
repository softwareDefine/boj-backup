#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<long long > vc;
long long arr[1000001];
int n;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		long long a;
		cin >> a;
		vc.push_back(a);
		arr[i] = a;
	}
	sort(vc.begin(), vc.end());
	vc.erase(unique(vc.begin(), vc.end()),vc.end());
	for (int i = 0; i < n; i++) {
		cout << lower_bound(vc.begin(), vc.end(), arr[i]) - vc.begin() << ' ';
	}
}