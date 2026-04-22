#include <iostream>
#include <algorithm>
#include <vector>

using ll = long long;
using namespace std;
vector<ll> vc;
vector<ll> coors;
ll arr[1000010];
ll mmx;
int n,q;
int main()
{
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		ll x,y;
		cin >> x >> y;
		vc.push_back(y);
		coors.push_back(y);
	}
	sort(coors.begin(), coors.end());
	coors.erase(unique(coors.begin(), coors.end()), coors.end());
	for (int i = 0; i < n; i++) {
		vc[i] = lower_bound(coors.begin(), coors.end(), vc[i]) - coors.begin();
	}
	for (int i = 0; i <	q; i++) {
		ll sidx, eidx , val;
		cin >> sidx >> eidx >> val;
		if (vc[sidx - 1] > vc[eidx - 1]) {
			swap(sidx, eidx);
		}
		arr[vc[sidx - 1]] += val;
		arr[vc[eidx-1]+1] -= val;
	}
	for (int i = 0; i < 1000010; i++) {
		ll k = (i - 1 >= 0) ? arr[i - 1] : 0;
		arr[i] += k;
		mmx = max(arr[i], mmx);
	}
	cout << mmx;
}