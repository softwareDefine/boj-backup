#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <stdio.h>

using ll = long long;
using namespace std;

ll n;
int cnt = 0;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char a, b;
		int now;
		scanf("%c%c%d",&a,&b,&now);
		if (abs(now) <= 90) {
			cnt++;
		}
	}
	printf("%d", cnt);
}