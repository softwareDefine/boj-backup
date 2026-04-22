// a-322.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

int n, m;
int arr[1010][1010];
int sum;
int x, y;
int mmn = 1000101010;
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if ((i+j)%2 &&arr[i][j] < mmn) {
				x = i;
				y = j;
				mmn = arr[i][j];
			}
		}
	}
	if (n % 2 == 1) {
		for (int j = 0; j < n; j++) {
			for (int i = 0; i < m - 1; i++) {
				if (j % 2 == 0) {
					cout << "R";
				}
				else {
					cout << "L";
				}
			}
			if (j != n - 1) {
				cout << "D";
			}
		}
	}
	else if (m % 2 == 1) {
		for (int j = 0; j < m; j++) {
			for (int i = 0; i < n - 1; i++) {
				if (j % 2 == 0) {
					cout << "D";
				}
				else {
					cout << "U";
				}
			}
			if (j != m - 1) {
				cout << "R";
			}
		}
	}
	else {
		int nn =( x % 2 )? x - 1 : x;
		for (int i = 0; i < nn; i++) {
			for (int j = 0; j < m - 1; j++) {
				if (i % 2 == 0) {
					cout << "R";
				}
				else {
					cout << "L";
				}
			}
			cout << "D";
		}
		int nm = y;
		for(int i=0;i<nm;i++){
			if (i % 2 == 0) {
				cout << "DR";
			}
			else {
				cout << "UR";
			}
		}
		for (int i = nm; i < m-1; i++) {
			if (i % 2 == 0) {
				cout << "RD";
			}
			else {
				cout << "RU";
			}
		}
		if (x % 2 == 0) {
			nn = n - (x + 2);
		}
		else {
			nn = n - (x + 1);
		}
		for (int i = 0; i < nn; i++) {
			cout << "D";
			for (int j = 0; j < m - 1; j++) {
				if (i % 2 == 0) {
					cout << "L";
				}
				else {
					cout << "R";
				}
			}
		}
	}
}