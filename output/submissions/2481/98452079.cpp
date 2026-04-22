#include <bits/stdc++.h>

using namespace std;

int n,k;
int m;

map<string,int> change;
string arr[200000];

vector<int> edge[200000];

queue<pair<int,int>> qu;

int visited[200000];
int before[200000];

void bfs(){
    visited[1] = 0;
    before[1] = -1;
    qu.push({1,0});
    while(!qu.empty()){
        auto [now,cnt] = qu.front();
        qu.pop();
        for(auto next : edge[now]){
            if(visited[next] != 99999999){
                visited[next] = cnt+1;
                before[next] = now;
                qu.push({next,cnt+1});
            }
        }
    }
}

void rev(int now){
    if(now == -1){
        return;
    }
    rev(before[now]);
    cout << now << ' ';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fill(visited,visited+200000,99999999);
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
        change[arr[i]] = i;
    }
    for(int i=1;i<=n;i++){
        string tmp = arr[i];
        for(int j=0;j<k;j++){
            if(tmp[j] == '1'){
                tmp[j] = '0';
            }else{
                tmp[j] = '1';
            }
            if(change.find(tmp) != change.end()){
                edge[i].push_back(change[tmp]);
            }
            if(tmp[j] == '1'){
                tmp[j] = '0';
            }else{
                tmp[j] = '1';
            }
        }
    }
    bfs();
    cin >> m;
    while(m--){
        int e;
        cin >> e;
        if(!before[e]){
            cout << -1 << '\n';
        }else{
            rev(e);
            cout << '\n';
        }
    }
}