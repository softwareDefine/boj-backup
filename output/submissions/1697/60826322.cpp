#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

vector<int> adj[100010];
int dist[100010];

int mmn = 999999;
int m , n;
int bfs(int s){
    memset(dist,-1,sizeof dist);
    queue<int> q;
    q.push(s);
    dist[s] = 0;
    while(!q.empty()){
        int cur = q.front();
        if(cur == n){
            return dist[cur];
        }
        q.pop();
        for(auto& nww : {cur-1,cur+1,cur*2}){
        if(dist[nww] == -1 && nww >= 0  && nww <= 100000){
            dist[nww] = dist[cur] +1;
            q.push(nww);
        }
        }
    }

}

int main()
{
   cin >>m >> n;
   printf("%d",bfs(m));

    return 0;
}
