#include <iostream>
#include <vector>
#include <string>

using ll = long long;
using namespace std;
vector<string> ptr[51];
string str;
int dp[51][51];
bool visit[51][51];
int child[26] = { 0 , };
int child2[26] = { 0 , };
int n;

int go(int start,int end){
	if (visit[start][end]) {
		return dp[start][end];
	}
	visit[start][end] = 1; 
	fill(child, child + 26, 0);
	for (int i = start; i <= end; i++) {
		child[str[i] - 'a']++;
	}
	for (auto& i : ptr[end - start + 1]) {
		fill(child2, child2 + 26, 0);
		int cnt = 0;
		int flag = 0;
		for (int j = 0; j < i.size(); j++) {
			child2[i[j] - 'a']++;
		}
		for (int j = 0; j < 26; j++) {
			if (child[j] != child2[j]) {
				flag = 1;
				break;
			}
		}
		if (flag) {
			continue;
		}
		for (int j = start; j <= end; j++) {
			if (str[j] != i[j - start]) {
				cnt++;
			}
		}
		dp[start][end] = min(cnt, dp[start][end]);
	}
	for (int k = start; k < end; k++) {
		dp[start][end] = min(dp[start][end], go(start,k) + go(k+1,end));
	}
	return dp[start][end];
}

int main()
{
	for (int i = 0; i < 51; i++) {
		for (int j = 0; j < 51; j++) {
			dp[i][j] = 999999;
		}
	}
	cin >> str;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string astr;
		cin >> astr;
		ptr[astr.size()].push_back(astr);
	}
	go(0, str.size() - 1);
	if (dp[0][str.size() - 1] == 999999) {
		cout << -1 << '\n';
	}
	else {
		cout << dp[0][str.size() - 1];
	}
}