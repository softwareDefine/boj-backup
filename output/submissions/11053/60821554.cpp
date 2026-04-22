#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <math.h>


using namespace std;

int lis[1010]={1, };
int input[1010];
int mmx=-99999;
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
	for (int i = 0; i < num; i++) {
		if (mmx < lis[i]) {
			mmx = lis[i];
		}
	}
	printf("%d", mmx);
}