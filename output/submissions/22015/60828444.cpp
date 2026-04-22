#include <iostream>
#include <algorithm>

using namespace std;

int arr[3];
int main()
{
	for (int i = 0; i < 3; i++) {
		cin >> arr[i];
	}
	int mmx = max(max(arr[0],arr[1]),arr[2]);
	cout << abs(mmx - arr[0]) + abs(mmx - arr[1]) + abs(mmx - arr[2]);
}