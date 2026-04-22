// a-464.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using ll = long long;
using namespace std;

ll n, k;
priority_queue<ll> pq;
vector<pair<ll, ll>> vc;
vector<ll> vc1[1000010];
vector<ll> vc2[1000010];
int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		ll a;
		cin >> a;
		vc.push_back({ a ,0 });
	}
	for (int i = 0; i < n; i++) {
		ll b;
		cin >> b;
		vc[i].second = b;
	}
	sort(vc.begin(), vc.end());
	for (int i = 0; i < n; i++) {
		vc1[vc[i].first].push_back( vc[i].second );
	}
	for (int i = 1; i <= n; i++) {
		sort(vc1[i].begin(), vc1[i].end());
		if (vc1[i].empty()) {
			continue;
		}
		for (int j = 0; j < vc1[i].size(); j++) {
			vc2[j+1].push_back(vc1[i][j]);
		}
	}
	long long sum = 0;
	for (int i = 1; i <= n; i++) {
		sort(vc2[i].begin(), vc2[i].end());
		for (auto& j : vc2[i]) {
			if (pq.size() < k) {
				sum += j;
				pq.push(j);
				continue;
			}
			else if(pq.top() > j) {
				sum += j - pq.top();
				pq.pop();
				pq.push(j);
			}
		}
		if (pq.size() < k) {
			cout << -1 << ' ';
		}
		else {
			cout << sum << ' ';
		}
	}
}