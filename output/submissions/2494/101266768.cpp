#include <bits/stdc++.h>

using namespace std;

typedef struct{
    int now;
    int Rightspin;
    int plusminus;
}Node;

int n;

string cur;
string fut;

int dp[12000][20];
Node before[12000][20];
int sNow, sRightspin;
int mmn = 999999999;

queue<pair<int,int>> qu;

vector<int> rev;

void bfs(int sn,int sR) {
	qu.push({sn,sR});
	while(!qu.empty()) {
		int now = qu.front().first;
		int Rightspin = qu.front().second;
		qu.pop();
		if(now == n){
		    if(mmn > dp[now][Rightspin]){
		        mmn = dp[now][Rightspin];
		        sNow = now;
		        sRightspin = Rightspin;
		    }
		    continue;
		}
		int current = cur[now] - '0';
		current = (Rightspin + current)%10;
		int future = fut[now] - '0';
		if(current > future) {
			if(dp[now+1][(Rightspin+future+10 - current)%10] > dp[now][Rightspin] + future+10 - current) {
				dp[now+1][(Rightspin+future+10 - current)%10] = dp[now][Rightspin] + future+10 - current;
				before[now+1][(Rightspin+future+10 - current)%10] = {now, Rightspin, future+10-current};
				qu.push({now+1,(Rightspin + future+10-current)%10});
			}
			if(dp[now+1][Rightspin] > dp[now][Rightspin] + current - future){	
			    dp[now+1][Rightspin] = dp[now][Rightspin] + current - future;
			    before[now+1][Rightspin] = {now, Rightspin, -(current- future)};
				qu.push({now+1,Rightspin});
			}
		} else {
			if(dp[now+1][Rightspin] > dp[now][Rightspin] + current+10-future) {
				dp[now+1][Rightspin] = dp[now][Rightspin] + current+10-future;
				before[now+1][Rightspin] = {now, Rightspin, -(current+10-future)};
				qu.push({now+1,Rightspin});
			}
			if(dp[now+1][(Rightspin+future-current)%10] > dp[now][Rightspin] + future - current) {
				dp[now+1][(Rightspin+future-current)%10] = dp[now][Rightspin] + future - current;
				before[now+1][(Rightspin+future-current)%10] = {now, Rightspin, future - current};
				qu.push({now+1,(Rightspin+future-current)%10});
			}
		}
	}
}

int main() {
	cin >> n;
	cin >> cur;
	cin >> fut;
	for(int i = 1; i < 12000; i++){
    	for(int j = 0; j < 20; j++){
    	    dp[i][j] = 999999999;
    	}
	}
	bfs(0,0);
	cout << mmn;
	do{
	    rev.push_back(before[sNow][sRightspin].plusminus);
	    int tmp = before[sNow][sRightspin].now;
	    int tmp2 = before[sNow][sRightspin].Rightspin;
	    sNow = tmp;
	    sRightspin = tmp2;
	}while(before[sNow][sRightspin].now != 0);
	rev.push_back(before[sNow][sRightspin].plusminus);
	reverse(rev.begin(),rev.end());
	cout << '\n';
	for(int i = 0; i < rev.size(); i++){
	    cout << i+1 << ' ' << rev[i] << '\n';
	}
}