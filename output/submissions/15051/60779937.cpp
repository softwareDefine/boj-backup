#include <iostream>

using namespace std;
int a, b;
int arr[3];
int mmx;
int mmxidx;
int sum=99999999999;
int main()
{
	for (int i = 0; i < 3; i++) {
		cin >> arr[i];
	}
	for (int j = 0; j < 3; j++) {
		int smallsum = 0;
		for (int i = 0; i < 3; i++) {
			smallsum += arr[i] * abs(i - j) * 2;
		}
		sum = min(sum, smallsum);
	}
	cout << sum;
}