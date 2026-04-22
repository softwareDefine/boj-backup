#include <bits/stdc++.h>

using namespace std;


int cost[11000];
vector<pair<int,int>> vc[11000];
int n,d;

bool cmp (pair<int,int> a,pair<int,int> b){
    return a.first < b.first;
}

int main(){
    cin >> n >> d;
    for(int i=0;i<=d;i++){
        cost[i]= 999999;
    }
    cost[0] = 0;
    for(int i=0;i<n;i++){
        int u, v, c;
        cin >> u >> v >> c;
        vc[u].push_back({v,c});
    }
    for(int i=0;i<=d;i++){
        sort(vc[i].begin(),vc[i].end(),cmp);
        cost[i+1] = min(cost[i]+1,cost[i+1]);
        for(auto &j : vc[i]){
            cost[j.first] = min(cost[j.first],cost[i]+j.second);
        }
    }
    cout << cost[d];
}