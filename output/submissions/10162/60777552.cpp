#include <iostream>
#include <string>

using namespace std;

string str;

int arr[30];
int a;
int cnt1, cnt2, cnt3;
int main()
{
	cin >> a;
	while (a >= 300) {
		a -= 300;
		cnt1++;
	}
	while (a >= 60) {
		a -= 60;
		cnt2++;
	}
	while (a >= 10) {
		a -= 10;
		cnt3++;
	}
	if (a > 0) {
		cout << "-1";
	}
	else {
		cout << cnt1 << " " << cnt2 << " " << cnt3;
	}
	
}