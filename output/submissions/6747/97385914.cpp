#include <bits/stdc++.h>

using namespace std;

int t;
int n,m;
vector<int> edge[200];
int in[200];
set<int> lightlist[200];
int heavy[200];
int cnt = 0;
queue<int> qu;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> t;
    while(t--){
        cnt = 0;
        for(int i=0;i<100;i++){
            edge[i].clear();
            lightlist[i].clear();
            heavy[i] = 0;
            in[i] = 0;
        }
        cin >> n >> m;
        for(int i=0;i<m;i++){
            int s,e;
            cin >> e >> s;
            in[e]++;
            edge[s].push_back(e);
        }
        for(int i=1;i<=n;i++){
            if(!in[i]){
                qu.push(i);
                in[i]= -9999999;
            }
        }
        while(!qu.empty()){
            int now = qu.front();
            qu.pop();
            for(auto next : edge[now]){
                for(auto compo : lightlist[now]){
                    lightlist[next].insert(compo);
                }
                lightlist[next].insert(now);
                in[next]--;
            }
            for(int i=1;i<=n;i++){
                if(!in[i]){
                    qu.push(i);
                    in[i]= -9999999;
                }
            }
        }
        for(int i=1;i<=n;i++){
            if((n+1)/2 <= lightlist[i].size()){
                cnt++;
            }
            for(auto compo : lightlist[i]){
                heavy[compo]++;
            }
        }
        for(int i=1;i<=n;i++){
            if((n+1)/2 <= heavy[i]){
                cnt++;
            }
        }
        cout << cnt;   
    }
}