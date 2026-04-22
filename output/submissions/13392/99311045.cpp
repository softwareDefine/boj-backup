#include <bits/stdc++.h>

using namespace std;

int n;

string cur;
string fut;

int dp[2][20];
int mmn = 999999999;

queue<pair<int,int>> qu;

void bfs(int sn,int sR) {
	qu.push({sn,sR});
	while(!qu.empty()) {
		int now = qu.front().first;
		int Rightspin = qu.front().second;
		qu.pop();
		if(now == n){
		    mmn = min(mmn,dp[now%2][Rightspin]);
		    continue;
		}
		int current = cur[now] - '0';
		current = (Rightspin + current)%10;
		int future = fut[now] - '0';
		if(current > future) {
			if(dp[(now+1)%2][(Rightspin+future+10 - current)%10] > dp[now%2][Rightspin] + future+10 - current) {
				dp[(now+1)%2][(Rightspin+future+10 - current)%10] = dp[now%2][Rightspin] + future+10 - current;
				qu.push({now+1,(Rightspin + future+10-current)%10});
			}
			if(dp[(now+1)%2][Rightspin] > dp[now%2][Rightspin] + current - future){	
			    dp[(now+1)%2][Rightspin] = dp[now%2][Rightspin] + current - future;
				qu.push({now+1,Rightspin});
			}
			dp[now%2][Rightspin] = 999999999;
		} else {
			if(dp[(now+1)%2][Rightspin] > dp[now%2][Rightspin] + current+10-future) {
				dp[(now+1)%2][Rightspin] = dp[now%2][Rightspin] + current+10-future;
				qu.push({now+1,Rightspin});
			}
			if(dp[(now+1)%2][(Rightspin+future-current)%10] > dp[now%2][Rightspin] + future - current) {
				dp[(now+1)%2][(Rightspin+future-current)%10] = dp[now%2][Rightspin] + future - current;
				qu.push({now+1,(Rightspin+future-current)%10});
			}
			dp[now%2][Rightspin] = 999999999;
		}
		if(now == 0){
		    for(int i=0;i<20;i++){
		        dp[now][i] = 999999999;
		    }
		}
	}
}

int main() {
	cin >> n;
	cin >> cur;
	cin >> fut;
	for(int i=0;i<20;i++){
	    dp[1][i] = 999999999;
	}
	bfs(0,0);
	cout << mmn;
}