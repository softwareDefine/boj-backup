#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

using namespace std;

int input;

int arr[150000] = {0,};
int sum[150000] = { 0, };
int main(){
	int num;
	int many;
	int a, b;
	scanf("%d %d",&num,&many);
	for (int i = 0; i < num; i++){
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i <num; i++){
		if (i == 0){
			sum[0] = arr[0];
			continue;
		}
		sum[i] = arr[i] + sum[i - 1];
	}
	for (int i = 0; i < many; i++){
		scanf("%d %d", &a, &b);
		printf("%d\n",sum[b-1] - sum[a-2]);
	}
}