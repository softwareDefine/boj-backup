// a-228.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

int n, m;
string a[50];
int mmn = 999999;

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i <= n-8; i++) {
		for (int j = 0; j <= m-8; j++) {
			int cnt1 = 0;
			int cnt2 = 0;
			int check = 0;
			for (int k = i; k < i + 8;k++) {
					for (int m = j; m < j + 8; m++) {
						if ((k-i)% 2 == 0 && check % 2 == 1 && a[k][m] == 'B') {
							cnt1++;
						}
						else if ((k - i) % 2 == 0 && check % 2 == 0 && a[k][m] == 'W') {
							cnt1++;
						}else if ((k - i) % 2 == 1 && check % 2 == 0 && a[k][m] == 'B') {
							cnt1++;
						}
						else if ((k - i) % 2 == 1 && check % 2 == 1 && a[k][m] == 'W') {
							cnt1++;
						}
						check++;
					}
				}
			check = 0;
			for (int k = i; k < i + 8; k++) {
					for (int m = j; m < j + 8; m++) {
						if ((k - i) % 2 == 0 && check % 2 == 1 && a[k][m] == 'W') {
							cnt2++;
						}
						else if ((k - i) % 2 == 0 && check % 2 == 0 && a[k][m] == 'B') {
							cnt2++;
						}else if ((k - i) % 2 == 1 && check % 2 == 0 && a[k][m] == 'W') {
							cnt2++;
						}
						else if ((k - i) % 2 == 1 && check % 2 == 1 && a[k][m] == 'B') {
							cnt2++;
						}
						check++;
					}
				}
			mmn = min(min(cnt1,cnt2), mmn);
		}
	}
	cout << mmn;
}