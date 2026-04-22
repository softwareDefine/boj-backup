#include <bits/stdc++.h>

using namespace std;

int n;

int mp[60][60];

int k, m;

pair<int,int> startPoint, endPoint;

typedef struct{
    int i;
    int j;
    int cnt;
}Node;

queue<Node> qu;
int cost[60][60];
int before[60][60];

int ans = 999999;

vector<pair<int,int>> ans2;

int main(){
    cin >> n;
    cin >> startPoint.first >> startPoint.second >> endPoint.first >> endPoint.second;
    cin >> k;
    cin >> m;
    while(m--){
        int turn;
        vector<pair<int,int>> point;
        cin >> turn;
        point.resize(turn);
        for(auto &[a, b] : point){
            cin >> a >> b;
        }
        for(int i = 0; i < turn-1; i++){
            if( point[i].first == point[i+1].first ){
                int s = min(point[i].second, point[i+1].second), e = max(point[i].second, point[i+1].second);
                for(int fill = s; fill <= e; fill++){
                    mp[point[i].first][fill] = 1;   
                }
            }else if( point[i].second == point[i+1].second ){
                int s = min(point[i].first, point[i+1].first), e = max(point[i].first, point[i+1].first);
                for(int fill = s; fill <= e; fill++){
                    mp[fill][point[i].second] = 1;   
                }
            }
        }
    }
    for(int i = 0; i < 60; i++){
        for(int j = 0; j < 60; j++){
            cost[i][j] = 999999;
            before[i][j] = -1;
        }
    }
    qu.push({startPoint.first, startPoint.second, (mp[startPoint.first][startPoint.second]?k:1)});
    while(!qu.empty()){
        auto [i, j, cnt] = qu.front();
        if(endPoint.first == i && endPoint.second == j){
            if( ans > cnt ){
                ans = cnt;
            }
        }
        qu.pop();
        if(i-1 > 0 && cost[i-1][j] > cnt + (mp[i-1][j]?k:1)){
            qu.push({i-1, j, cnt + (mp[i-1][j]?k:1)});
            cost[i-1][j] = cnt + (mp[i-1][j]?k:1);
            before[i-1][j] = 0;
        }
        if(i+1 <= n && cost[i+1][j] > cnt + (mp[i+1][j]?k:1)){
            qu.push({i+1, j, cnt + (mp[i+1][j]?k:1)});
            cost[i+1][j] = cnt + (mp[i+1][j]?k:1);
            before[i+1][j] = 1;
        }
        if(j-1 > 0 && cost[i][j-1] > cnt + (mp[i][j-1]?k:1)){
            qu.push({i, j-1, cnt + (mp[i][j-1]?k:1)});
            cost[i][j-1] = cnt + (mp[i][j-1]?k:1);
            before[i][j-1] = 2;
        }
        if(j+1 <= n && cost[i][j+1] > cnt + (mp[i][j+1]?k:1)){
            qu.push({i, j+1, cnt + (mp[i][j+1]?k:1)});
            cost[i][j+1] = cnt + (mp[i][j+1]?k:1);
            before[i][j+1] = 3;
        }
    }
    cout << ans << '\n';
    int ci = endPoint.first, cj = endPoint.second;
    before[startPoint.first][startPoint.second] = -1;
    int whatIUsed = -1;
    do{
        if(whatIUsed != before[ci][cj]){
            whatIUsed = before[ci][cj];
            ans2.push_back({ci, cj});
        }
        switch(before[ci][cj]){
            case 0:
                ci += 1;
                break;
            case 1:
                ci -= 1;
                break;
            case 2:
                cj += 1;
                break;
            case 3:
                cj -= 1;
                break;
        }
    }while(before[ci][cj] != -1);
    ans2.push_back(startPoint);
    reverse(ans2.begin(), ans2.end());
    cout << ans2.size() << ' ';
    for(auto &[a, b] : ans2){
        cout << a << ' ' << b << ' ';
    }
}