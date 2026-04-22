#include <bits/stdc++.h>

using namespace std;

int n,m,r;
int items[500];
vector<pair<int,int>> edge[500];
//map<int,pair<int,int>> road;
int visited[500];

int mmx;

int go(int now,int before,int left){
    int sum = 0;
    if(!visited[now]){
       sum += items[now];
       visited[now] = 1;
    }
    for(auto [next,cost] : edge[now]){
        if(left-cost >= 0 && next != before){
            //road[]
            sum += go(next,now,left-cost);
        }
    }
    return sum;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
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
        mmx = max(mmx, go(i,-1,m));
    }
    cout << mmx;
}