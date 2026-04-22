#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
vector<ll> base;
ll t;
// 몇번 하는지 하는것
ll cnt(ll num) {
	ll tmp = 1, ret = 0;
	while (num) {
		num -= tmp;
		if (tmp * 2 > num) {
			tmp = 1;
		}
		else { tmp *= 2; }
		ret++;
	}
	return ret;
}

ll DnC(ll start, ll end) {
	if (start == end) return cnt(start);
	if (end - start == 1) return max(cnt(start), cnt(end));
	ll i;
	for (i = 0; i < 31; i++) {
		if (base[i] > end) {
			break;
		}
	}
	if (base[i - 1] >= start) {
		if (base[i - 2] >= start) {
			return max(i - 2 + DnC(0, base[i - 2]), i - 1 + DnC(0,end - base[i - 1]));
		}
		else if (base[i - 1] == start) {
			return i - 1 + DnC(0, end - base[i - 1]);
		}
		else {
			return max(i - 2 + DnC(start - base[i - 2], base[i - 2]), i - 1 + DnC(0, end - base[i - 1]));
		}
	}
	else {
		return i - 1 + DnC(start - base[i - 1], end - base[i - 1]);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	ll temp = 1;
	for (ll i = 0; i < 31; i++) {
		base.push_back(temp - 1);
		temp *= 2;
	}
	cin >> t;
	while (t--) {
		ll start, end;
		cin >> start >> end;
		cout << DnC(start, end) << '\n';
	}
}