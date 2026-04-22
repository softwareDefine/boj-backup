#include <iostream>
#include <algorithm>

using namespace std;

pair<int, int> d[100001];
int idt[1 << 22];
int cmp(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}

void update(int n) {
	while (n > 1) {
		if (idt[n] > idt[n / 2]) {
			idt[n / 2] = idt[n];
		}
		n >>= 1;
	}
}

int query(int st, int ed) {
	int m = 0;
	while (st < ed) {
		m = max(m, idt[ed]);
		if (!(ed % 2)) {
			ed--;
		}
		ed >>= 1;
		st >>= 1;
	}
	if (st == ed) {
		m = max(m, idt[st]);
	}
	return m;
}
int main()
{
	int i, base, n, mmn = -1;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> d[i].first >> d[i].second;
		if (mmn < d[i].second) mmn = d[i].second;
	}
	sort(d + 1, d + n + 1, cmp);
	for (base = 1; base < mmn; base <<= 1);
	for (i = 1; i <= n; i++) {
		idt[base + d[i].second - 1] = query(base, base + d[i].second - 2) + 1;
		update(base + d[i].second - 1);
	}
	cout << n - idt[1];
}