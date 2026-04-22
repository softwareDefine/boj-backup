#include <bits/stdc++.h>

using namespace std;

int n,m,k,x;
vector<int> edge[310000];
int cost[310000];
vector<int> city;

void solve(int start){
    queue<int> qu;
    cost[start] = 0;
    qu.push(start);
    while(!qu.empty()){
        int now = qu.front();
        qu.pop();
        for(auto &next : edge[now]){
            if(cost[next] > cost[now] + 1){
                cost[next] = cost[now] + 1;
                qu.push(next);
            }
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    for(int i=1;i<=300010;i++){ cost[i] = 999999999;    }
    cin >> n >> m >> k >> x;
    while(m--){
        int u,v;
        cin >> u >> v;
        edge[u].push_back(v);
    }
    solve(x);
    for(int i=1;i<=n;i++){
        if(cost[i] == k){
            city.push_back(i);
        }
    }
    if(city.size()){
        for (auto &i : city){
            cout << i << '\n';
        }
    }else{
        cout << -1;
    }
}