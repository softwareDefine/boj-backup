#include <iostream>

using namespace std;
int n, m;
int arr[550][550];
int dp[550][550];
int visited[550][550];
int dy[4] = {0,1,0,-1};
int dx[4] = { 1,0,-1 ,0};
int cnt;

int dfs(int y,int x,int least) {
	if (x == m - 1 && y == n - 1) {
		return 1;
	}
	else if (dp[y][x] == -1) {
		dp[y][x] = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < m && ny < n && nx >= 0 && ny >= 0 && least > arr[ny][nx] && visited[ny][nx]!=1) {
			int nl = arr[ny][nx];
			visited[ny][nx] = 1;
			dp[y][x] += dfs(ny,nx ,nl);
			visited[ny][nx] = 0;
		}
	}
	}
	return dp[y][x];
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dp[i][j] = -1;
			cin >> arr[i][j];
		}
	}
	cout << dfs(0,0,arr[0][0]);
}