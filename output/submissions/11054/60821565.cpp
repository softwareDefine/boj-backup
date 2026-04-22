#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <math.h>


using namespace std;

int lis[1010]={1, };
int lis2[1010] = { 1, };
int input[1010];
int mmx=-99999;
int mmx2 = -9999;
int startmmx;
int main()
{
	int num;
	scanf("%d",&num);
	for (int i = 0; i < num; i++) {
		scanf("%d", &input[i]);
	}
	
	for (int i = 0; i < num; i++) {
		lis[i] = 1;
		for (int j = 0; j < i; j++) {
			if (input[i] > input[j]) {
				lis[i] = max(lis[j] + 1, lis[i]);
				
			}
		}
	}
	for (int i = num-1; i >=0; i--) {
		lis2[i] = 1;
		for (int j = num-1; j > i; j--) {
			if (input[i] > input[j]) {
				lis2[i] = max(lis2[j] + 1, lis2[i]);
			}
		}
	}
	for (int i = 0; i < num; i++) {
		if (mmx < lis[i] + lis2[i]) {
			mmx = lis[i] + lis2[i];
		}
	}
	printf("%d", mmx-1);
}