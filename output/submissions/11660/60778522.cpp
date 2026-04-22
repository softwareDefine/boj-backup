#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int n, m;
int arr[1026][1026];
int sum[1026][1026];

void summer() {
	int total=0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j-1] + arr[i][j];
		}
	}
}
int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d ", &arr[i][j]);
		}
	}
	summer();
	
	for (int i = 1; i <= m; i++) {
		int x1, x2, y1, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		printf("%d\n",sum[x2][y2] - sum[x1-1][y2] - sum[x2][y1-1] + sum[x1-1][y1-1]);
	}
}