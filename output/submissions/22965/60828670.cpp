// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int cnt,cnt2;
int mmn = 9999999999,mmnidx;
int before;
vector<int> vc;
int istrue;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		vc.push_back(a);
		if (mmn > a) {
			mmn = a;
			mmnidx = i;
		}
	}
	for (int i = 1; i < n; i++) {
		if (vc[i]< vc[i - 1]) {
			cnt++;
		}
	}
	for (int i = mmnidx; i < mmnidx + n; i++) {
		if (vc[i%n] > before) {
			before = vc[i%n];
		}
		else {
			istrue = true;
			break;
		}
	}
	if (cnt == 0) {
		cout << 1;
	}
	else if (istrue == false) {
		cout << 2;
	}
	else {
		cout << 3;
	}
}
