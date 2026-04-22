// a-5.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int cnt;
int mmn;
vector<int> vc;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		vc.push_back(a);
	}
	sort(vc.begin(), vc.end());
	vc.erase(unique(vc.begin(), vc.end()), vc.end());
	for (int i = 0; i < vc.size(); i++) {
		if (vc[i] == i) {
			cnt++;
		}
		else {
			break;
		}
	}
	if (cnt == 1 && vc.size()==1) {
		cout << 1;
	}
	else if (cnt == 0) {
		cout << 0;
	}
	else {
		cout << cnt + 2;
	}
	
}