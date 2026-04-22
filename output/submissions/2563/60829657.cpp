#include <iostream>

using namespace std;

int arr[110][110];
int n;
int mmx;
int getter;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		for (int j = a; j < a+10; j++) {
			for (int z = b; z < b+10; z++) {
				arr[j][z]++;
			}
		}
	}
	for (int j = 0; j < 110; j++) {
		for (int z = 0; z < 110; z++) {
			if (arr[j][z] > 0) {
				getter++;
			}
		}
	}
	cout << getter;
}