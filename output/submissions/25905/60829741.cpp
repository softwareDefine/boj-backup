#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

double arr[11];
double a[11];
double msum = 0.00000001;
bool check[11];
void go(int idx,int start) {
	if (idx == 9) {
		double sum = 1;
		for (int i = 0; i < 9;i++) {
			sum *= a[i];
		}
		sum *= pow(10, 9);
		msum = max(msum,sum);
		return;
	}
	for (int i = 0; i < 10; i++) {
		if (check[i]) {
			continue;
		}
		check[i] = true;
		a[idx] = arr[i] / (idx+1);
		go(idx+1,i+1);
		check[i] = false;
	}
}

int main()
{
	for (int i = 0; i < 10; i++) {
		cin >> arr[i];
	}
	go(0,0);
	printf("%.10lf", msum);
}