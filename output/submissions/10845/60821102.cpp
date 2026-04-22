    // queue-1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#define _CRT_SECURE_NO_WARINGS
#pragma warning(disable: 4996)

#include <stdio.h>
#include<string.h>
#include <queue>

using namespace std;

int main() {
	queue<int> a;
	int n;
	int pusher;
	char check[7]={};
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s",check);
		if(strcmp(check,"push") == 0) {
			scanf("%d", &pusher);
			a.push(pusher);
		}
		else if (strcmp(check, "pop") == 0){
			if (a.empty()) {
				printf("%d\n", -1);
				continue;
			}
			printf("%d\n", a.front());
			a.pop();
		}
		else if (strcmp(check, "size") == 0) {
			printf("%d\n", a.size());
		}
		else if (strcmp(check, "empty") == 0) {
			if (a.empty()) {
				printf("1\n");
				continue;
			}
			printf("0\n");
		}
		else if (strcmp(check, "front") == 0) {
			if (a.empty()) {
				printf("%d\n", -1);
				continue;
			}
			printf("%d\n", a.front());
		}
		else if (strcmp(check, "back") == 0) {
			if (a.empty()) {
				printf("%d\n", -1);
				continue;
			}
			printf("%d\n", a.back());
		}
	}
}