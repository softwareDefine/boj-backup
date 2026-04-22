#include <iostream>
#include <math.h>
#include <vector>
#include <queue>
#include <string.h>
#include <string>

using namespace std;
vector<pair<int,int>> vertex[100010];
int visited[100000];
int dist[100000];
int n,m,u,v;

void  dfs(int st){
        for(auto y : vertex[st]){
            if(visited[y.first]!=1){
               dist[y.first] = dist[st]+y.second;
               visited[y.first] = 1;
               dfs(y.first);  
              }    
        }
}

int main(){
    cin >> n >> m;
    for(int i=0;i<n-1;i++){
       int st,ed,val;
       cin >> st >> ed >> val;
        vertex[st].push_back({ed,val});
        vertex[ed].push_back({st,val});
     } 
     for(int i=0;i<m;i++){
      cin >> u >> v;
      memset(visited,0,sizeof(visited));
      memset(dist,0,sizeof(dist));
      visited[u]= 1;
      dist[u] = 0;
      dfs(u);
      cout << dist[v] <<'\n';   
     }
    return 0;
}