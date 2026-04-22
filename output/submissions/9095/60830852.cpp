#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

using namespace std;

int input;

int arr[10000] = {1,2,4,};
int main(){
	int num;
	
	scanf("%d", &num);
	for (int i = 3; i <10000; i++){
		arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
	}
	for (int i = 0; i < num; i++){
		scanf("%d", &input);
		printf("%d\n",arr[input - 1]);
	}
}