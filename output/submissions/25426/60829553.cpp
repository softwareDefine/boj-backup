#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
long long n;
long long sum;
vector<pair<long long,long long>> vc;

long long cmp(pair<long long, long long> a, pair<long long, long long> b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	return a.first < b.first;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (long long i = 0; i < n; i++) {
		long long a, b;
		cin >> a >> b;
		vc.push_back({ a,b });
	}
	stable_sort(vc.begin(),vc.end(),cmp);
	for (long long i = n-1; i >= 0; i--) {
		sum += vc[i].first * (i + 1) + vc[i].second;
	}
	cout << sum;
}