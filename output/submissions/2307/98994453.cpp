#include <bits/stdc++.h>

using lint = long long;
using namespace std;

typedef struct node{
    lint next;
    lint nc;
    lint idx;
};

vector<node> edge[2000];
lint cost[2000];
vector<lint> candidates;
priority_queue<pair<lint,pair<lint,lint>>> pq;

lint noGate;
lint yesGate[6000];

lint n,m;
lint mmx;

lint dik(lint banned,lint test){
    pq.push({-0,{1,1500}});
    while(!pq.empty()){
        int c = -pq.top().first;
        int now = pq.top().second.first;
        int candid = pq.top().second.second;
        pq.pop();
        if(cost[now] < c){continue;}
        if(test){candidates.push_back(candid);}
        for(auto [next,nc,idx] : edge[now]){
            if(cost[next] > c+nc && banned != idx){
                cost[next] = c+nc;
                pq.push({-cost[next],{next,idx}});
            }
        }
    }
    return cost[n];
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        lint a,b,t;
        cin >> a >> b >> t;
        edge[a].push_back({b,t,i});
        edge[b].push_back({a,t,i});
    }
    for(int i=1;i<=n;i++){
        sort(edge[i].begin(),edge[i].end(),[](auto a,auto b){
            return a.nc < b.nc;
        });
    }
    fill(cost,cost+n+1,99999999);
    noGate = dik(-1,1);
    for(auto element : candidates){
        fill(cost,cost+n+1,99999999);
        yesGate[element] = dik(element,0);
    }
    for(auto element : candidates){
        if(yesGate[element] == 99999999){
            cout << -1;
            exit(0);
        }
        mmx = max(mmx,yesGate[element]-noGate);
    }
    cout << mmx;
    return 0;
}