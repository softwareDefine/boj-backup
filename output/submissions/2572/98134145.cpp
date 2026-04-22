#include <bits/stdc++.h>

using namespace std;

int n;
int m,k;

char card[2000];

vector<pair<int,char>> vc[1000];

// 정점, 방문 개수 = 최대 일치 카드 점수수
int dp[1000][2000];


// 현재 방문 정점 , 방문 개수
queue<pair<int,int>> qu;

int mmx;

void bfs(int start){
    qu.push({start,0});
    while(!qu.empty()){
        int now = qu.front().first;
        int idx = qu.front().second;
        qu.pop();
        for(auto [next,color] : vc[now]){
            if(idx < n && dp[next][idx+1] < dp[now][idx] + (card[idx+1] == color?10:0)){
                qu.push({next,idx+1});
                dp[next][idx+1] = dp[now][idx] + (card[idx+1] == color?10:0);
            }
        }
    }
}

int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> card[i];
    }
    cin >> m >> k;
    for(int i=0;i<k;i++){
        int u,v; char color;
        cin >> u >> v >> color;
        vc[u].push_back({v,color});
        vc[v].push_back({u,color});
    }
    bfs(1);
    for(int i=1;i<=m;i++){
        mmx = max(mmx,dp[i][n]);
    }
    cout << mmx;
}