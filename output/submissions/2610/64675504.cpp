#define inf 999999999
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int parent[100010];
int dp[110][110];
int n,m;
vector<int> ans;
map<int,vector<int>> mp;
int find(int now){
    if(parent[now] == now){
        return now;
    }
    return parent[now] = find(parent[now]);
}

int merge(int st,int ed){
    int stp = find(st);
    int edp = find(ed);
    if(st!=ed){
        parent[stp] = edp;
    }
}

int main(){
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        parent[i] = i;
        for(int j=1;j<=n;j++){
            dp[i][j] = inf;
        }
    }
    for(int i=0;i<m;i++){
        int v,u;
        cin >> u >> v;
        dp[u][v] = 1;
        dp[v][u] = 1;
        merge(u,v);
    }
    for(int i=1;i<=n;i++) {
        mp[find(i)].push_back(i);
    }
    for(auto &t : mp){
        for(auto &k : t.second){
            for(auto &i : t.second){
                for(auto &j : t.second){
                    dp[i][j] = min(dp[i][k] + dp[k][j],dp[i][j]);
                }
            }
        }
        int mmn = inf+1;
        int mmnp = 0;
        for(auto &i : t.second){
            int mmx = 0;
            for(auto &j : t.second){
                if(i==j){ continue;}
                mmx = max(dp[i][j],mmx);
            }
            if(mmx < mmn){
                mmn = mmx;
                mmnp = i;
            }
        }
        ans.push_back(mmnp);
    }
    sort(ans.begin(),ans.end(),[&](auto a,auto b){
        return a < b;
    });
    cout << ans.size() << '\n';
    for(auto &i : ans){
        cout << i << '\n';
    }
}