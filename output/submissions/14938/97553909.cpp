#include <bits/stdc++.h>

using namespace std;

int n,m,r;
int items[500];
vector<pair<int,int>> edge[500];
int visited[500];

int mmx;

int go(int now,int left){
    int sum = items[now];
    for(auto [next,cost] : edge[now]){
        if(!visited[next] && left-cost >= 0){
            visited[next] = 1;
            sum += go(next,left-cost);
        }
    }
    return sum;
}

int main(){
    cin >> n >> m >> r;
    for(int i=1;i<=n;i++){
        cin >> items[i];
    }
    for(int i=0;i<r;i++){
        int a,b,l;
        cin >> a >> b >> l;
        edge[a].push_back({b,l});
        edge[b].push_back({a,l});
    }
    for(int i=1;i<=n;i++){
        memset(visited,0,sizeof(visited));
        mmx = max(mmx, go(i,r));
    }
    cout << mmx;
}