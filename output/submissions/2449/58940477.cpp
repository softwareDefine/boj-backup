#include <iostream>

using namespace std;

int arr[210];
int dp[210][210];
bool visited[210][210];
int n, k;
// 전체부분 문제를 반으로 분할정복하여, 각각의 구간을 전부 목표 상태로 만들기 위한 최솟값
int DnC(int start, int end) {
	if (start == end) { return 0; }
	if (visited[start][end]) {return dp[start][end];}
	visited[start][end] = 1;
	for (int i = start; i < end; i++) {
		int iSame = (arr[start] == arr[i + 1]) ? 0 : 1;
		dp[start][end] = min(dp[start][end], DnC(start, i)+DnC(i+1,end)+iSame );
	}
	return dp[start][end];
}

int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dp[i][j] = 999999999;
		}
	}
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << DnC(0, n - 1);
}