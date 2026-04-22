#include <iostream>
#include <vector>
#include <set>


using ll = long long;
using namespace std;

ll fail[1000010];
ll arr[1000010];
ll cnt;
ll n;
set<ll> preprocessing(ll n) {
	set<ll> st;
	for (ll i = 2; i <= n; i++) {
		if (fail[i]) continue;
		st.insert(i);
		for (ll j = 2 * i;j<=n ; j += i) fail[j] = 1;
	}
	return st;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	set<ll> st = preprocessing(1000000);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (ll i = 0; i < n; i++) {
		for (ll j = i+1;j < n; j++) {
			if (st.find(j - i+1)!=st.end()) {
				ll sum = 0;
				for (ll k = i; k <= j; k++) {
					sum += arr[k];
				}
				if (st.find(sum) != st.end()) {
					cnt++;
				}
			}
		}
	}
	cout << cnt;
	//누적합 투포인터 적당히 돌려서 시간복잡도 N으로 줄일수 있는데 머리가 고생하기 싫다. N^3으로 뚫려서 그냥간다.
}