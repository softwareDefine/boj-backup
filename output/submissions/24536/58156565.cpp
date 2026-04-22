// a-536.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

string str;
int n;
int arr[1000010];
int lisz[1000010];
int lisz2[1000010];
int mmn = 999999999;
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
		lisz[i] = lis.size();
		if (lis.empty()) { lis.push_back(arr[i]); continue; }
		if(lis.back() < arr[i] && str[i-1] == 'L') {
			lis.push_back(arr[i]);
		}
		else {
			if (str[i-1] == 'L') {
				int idx = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
				lis[idx] = arr[i];
			}
		}
	}
	for (int i = n;i > 0;i--) {
		lisz2[i] = lis2.size();
		if (lis2.empty()) { lis2.push_back(arr[i]); continue; }
		if (lis2.back() < arr[i] && str[i-1] == 'R') {
			lis2.push_back(arr[i]);
		}
		else {
			if (str[i-1] == 'R') {
				int idx = lower_bound(lis2.begin(), lis2.end(), arr[i]) - lis2.begin();
				lis2[idx] = arr[i];
			}
		}
	}
	for (int i = 1;i <= n;i++) {
		if(str[i] == 'L'){ mmn = min(mmn, i +1 - lisz[i] + (n - i-1 ) - lisz2[i]); }
		else {
			mmn = min(mmn, i-1 - lisz[i] + (n - i+1) - lisz2[i]);
		}
	}
	cout << mmn;
}