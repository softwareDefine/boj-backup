// a-328.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using ll = long long;
using namespace std;
ll n;
ll mmx = 0;
ll arr[1000010];

ll DnC(ll start, ll end) {
	if (start == end) {
		return arr[start] * arr[start];
	}
	ll mid = (start + end) / 2;
	ll fd = DnC(start, mid);
	ll sd = DnC(mid + 1, end);
	mmx = max(fd, sd);
	ll left = mid;
	ll right = mid + 1;
	ll sum = arr[left] + arr[right];
	ll mmn = min(arr[left], arr[right]);
	mmx=max(mmx, sum * mmn);
	while (left > start || right < end) {
		if (right < end && (left == start || arr[left - 1] < arr[right + 1])) {
			sum += arr[++right];
			mmn = min(mmn, arr[right]);
		}
		else {
			sum += arr[--left];
			mmn = min(mmn, arr[left]);
		}
		ll ssum = sum * mmn;
		mmx = max(mmx, ssum);
	}
	return mmx;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << DnC(0, n - 1);
}