#include <iostream>
#include <vector>

using namespace std;
string str;
vector<char> vc;
int dp[2200][2200];
bool visited[2200][2200];

int go(int start, int end) {
	if (end <start) {
		return 0;
	}
	if (visited[start][end]) {
		return dp[start][end];
	}
	visited[start][end] = 1;
	if (start == end) {
		return dp[start][end] = 1;
	}
	if (str[start] == str[end]) {
		dp[start][end] = max( go(start + 1, end - 1)+2,dp[start][end]);
	}
	dp[start][end] = max(go(start + 1, end), dp[start][end]);
	dp[start][end] = max(go(start, end - 1), dp[start][end]);
	return dp[start][end];
}

void dfs(int start, int end) {
	if (start > end) {
		return;
	}
	if (start == end) {
		vc.push_back(str[start]);
		return;
	}
	if (str[start] == str[end] && dp[start+1][end-1]+2 == dp[start][end]) {
		vc.push_back(str[start]);
		return dfs(start + 1, end - 1);
	}
	if (dp[start][end - 1] > dp[start + 1][end]) {
		return dfs(start, end - 1);
	}else{
		return dfs(start + 1, end);
	}
}

int main()
{
	while (!cin.eof()) {
		for (int i = 0;i < 2200;i++) {
			for (int j = 0;j < 2200;j++) {
				dp[i][j] = 0;
				visited[i][j] = 0;
			}
		}
		vc.clear();
		str = string();
		cin >> str;
		go(0, str.size() - 1);
		if (dp[0][str.size() - 1] == 1 || dp[0][str.size() - 1] == 2) {
			continue;
		}
		dfs(0, str.size() - 1);
		for (auto& i : vc) {
			cout << i;
		}
		if (dp[0][str.size()-1] % 2) {
			for (int i = vc.size() - 2;i >= 0;i--) {
				cout << vc[i];
			}
		}
		else {
			for (int i = vc.size() - 1;i >= 0;i--) {
				cout << vc[i];
			}
		}
		cout << '\n';
	}
}