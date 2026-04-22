// a-188.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<long long> vc;
vector<long long> ans;
long long n, x;
long long cnt;
long long all;

int main()
{
	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		long long c;
		cin >> c;
		if (x == c) {
			cnt++;
			all++;
			continue;
		}
		vc.push_back(c);
	}
	sort(vc.begin(), vc.end());
	int i = 0;
	int j = vc.size() - 1;
	while (i < j) {
		if (vc[i] + vc[j] + x / 2 >= x) {
			all += 2;
			cnt++;
			j--;
		}
		i++;
	}
	cout << cnt + (n - all) / 3;
}