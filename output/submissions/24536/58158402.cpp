// a-536.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <vector>

using ll = long long;
using namespace std;

string str;
ll n;
ll arr[1000010];
ll lisz[1000010];
ll lisz2[1000010];
ll mmn = 999999999;
vector<int> lis;
vector<int> lis2;
int main()
{
	cin >> n;
	cin >> str;
	for (int i = 1;i <= n;i++) {
		cin >> arr[i];
	}
	for (int i = 1;i <= n;i++) {
		if (str[i - 1] == 'L') {
			if (lis.empty() ) { lis.push_back(arr[i]);}
			else if (lis.back() < arr[i] ) {
				lis.push_back(arr[i]);
			}
			else {
					ll idx = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
					lis[idx] = arr[i];
			}
		}
		lisz[i] = lis.size();
	}
	for (int i = n;i > 0;i--) {
		if (str[i-1] == 'R') {
			if (lis2.empty()) { lis2.push_back(arr[i]); }
			else if (lis2.back() < arr[i]) {
				lis2.push_back(arr[i]);
			}
			else {
				ll idx = lower_bound(lis2.begin(), lis2.end(), arr[i]) - lis2.begin();
				lis2[idx] = arr[i];
			}
		}
		lisz2[i] = lis2.size();
	}
	for (int i = 1;i <= n;i++) {
		if(str[i-1] == 'L'){ mmn = min(mmn, i - lisz[i] + (n -i) - lisz2[i+1]); }
		else {
			mmn = min(mmn, i-1 - lisz[i-1] + (n - i+1) - lisz2[i]);
		}
	}
	cout << mmn;
}