#include <iostream>
#include <algorithm>

using namespace std;

int arr[4];
int selection[2];
int sum;

int cmp(int a, int b) {
	return a > b;
}

int main()
{
	for (int i = 0; i < 4; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < 2; i++) {
		cin >> selection[i];
	}
	sort(arr, arr + 4,cmp);
	sort(selection, selection + 2,cmp);
	sum = arr[0] + arr[1] + arr[2];
	sum += selection[0];
	cout << sum;
}