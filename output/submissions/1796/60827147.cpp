#include <iostream>

using namespace std;
string str;
int dp [55][55];
bool visit[55][55];
bool exist[26];
int low[26];
int mmx[26];

int dist(int now, int next, int low, int mmx) {
	return abs(now - low) + abs(low - mmx) + abs(mmx - next);
}

int go(int cnt, int idx) {
	if (cnt == 26) {
		return 0;
	}
	if (visit[cnt][idx]) {
		return dp[cnt][idx];
	}
	int left = low[cnt];
	int right = mmx[cnt];
	if (exist[cnt]) {
		for (int i = 0; i < str.size(); i++) {
			dp[cnt][idx] = min(dp[cnt][idx], go(cnt + 1, i) + min(dist(idx, i, low[cnt], mmx[cnt]), dist(idx, i, mmx[cnt], low[cnt])));
		}
	}
	else {
		dp[cnt][idx] = go(cnt + 1, idx);
	}
	visit[cnt][idx] = 1;
	return dp[cnt][idx];
}

int main()
{
	for (int i = 0; i < 55; i++) {
		for (int j = 0; j < 55; j++) {
			dp[i][j] = 999999;
		}
	}
	cin >> str;
	fill(low, low + 26, 9999);
	for (int i = 0; i < str.size(); i++) {
		low[str[i] - 'a'] = min(i, low[str[i] - 'a']);
		mmx[str[i] - 'a'] = max(i, mmx[str[i] - 'a']);
		exist[str[i]-'a'] = 1;
	}
	cout << go(0,0)+str.size();
}