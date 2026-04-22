#include <iostream>
#include <cmath>

using namespace std;

int n;
double a, b, c,x,y,t;
int arr[3];
int main()
{
	cin >> a >> b >> c;
	for (int i = 0; i < 3; i++) {
		cin >> arr[i];
	}
	if (arr[0] >= a && arr[1] >= b && arr[2] >= c) {
		cout << "A";
	}
	else if (arr[0] >= a / 2 && arr[1] >= b && arr[2] >= c) {
		cout << "B";
	}
	else if (arr[1] >= b && arr[2] >= c) {
		cout << "C";
	}
	else if (arr[1] >= b / 2 && arr[2] >= c / 2) {
		cout << "D";
	}
	else {
		cout << "E";
	}
}