#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

int main()
{
	while (1) {
		
		float a;
		cin >> a;
		if (a == -1) {
			break;
		}
		printf("Objects weighing %.2f on Earth will weigh %.2f on the moon.\n", a ,a*0.167);
	}
}
