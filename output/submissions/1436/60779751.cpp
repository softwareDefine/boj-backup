#include <iostream>
#include <math.h>

using namespace std;

int n;

int main()
{
	cin >> n;

	int i = 0 ,j=665;
	while (i < n) {
		for (int k = 0; k < 10; k++) {
			if (j / (int)pow(10, k) % 1000 == 666) {
				i++;
				break;
			}
		}
		j++;
	}
	cout << j-1;
}
