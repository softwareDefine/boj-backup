#include <bits/stdc++.h>

using lint = long long;
using namespace std;

lint n,m,k;

lint arr[40000];
int parent[40000];
pair<lint,lint> total[40000];
vector<pair<lint,lint>> vc;
lint dp[5000];
lint mmx;

int find(int now){
    if(parent[now] == now){
        return now;
    }
    return parent[now] = find(parent[now]);
}

int main(){
    iota(parent,parent+40000,0);
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    while(m--){
        lint a,b;
        cin >> a >> b;
        if(b < a){swap(a,b);}
        parent[find(b)] = find(a);
    }
    for(int i=1;i<=n;i++){
        total[find(i)].second++;
        total[find(i)].first += arr[i];
    }
    for(int i=1;i<=n;i++){
        if(total[i].second){
            vc.push_back(total[i]);
        }
    }
    for(int i=0;i<vc.size();i++){
        for(int j=3000;j>=0;j--){
            dp[j+vc[i].second] = max(dp[j+vc[i].second], dp[j] + vc[i].first);
        }
    }
    cout << dp[k-1];
}