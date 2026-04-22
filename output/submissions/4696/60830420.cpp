#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

int main()
{
	while (1) {
		
		float a;
		cin >> a;
		if (a == 0) {
			break;
		}
		printf("%.2f\n", a + pow(a, 2) + pow(a, 3) + pow(a, 4) + 1);
	}
}
