#include <bits/stdc++.h>

using namespace std;

int n,k;
string code[3000];
vector<int> edge[3000];
int visited[3000];

queue<int> qu;

int s,e;

bool diff(string a, string b){
    int differentchar = 0;
    for(int w=0;w<k;w++){
        if(a[w] ^ b[w]){differentchar++;}
    }
    return (differentchar == 1);
}

void bfs(int s,int e){
    visited[s] = -1;
    qu.push(s);
    while(!qu.empty()){
        int now = qu.front();
        qu.pop();
        for(auto next : edge[now]){
            if(!visited[next]){
                visited[next] = now;
                qu.push(next);
            }
        }
    }
}

void reverse(int now){
    if(now == -1){
        return;
    }
    reverse(visited[now]);
    cout << now << ' ';
}

int main(){
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        cin >> code[i];
    }
    cin >> s >> e;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(diff(code[i],code[j])){
                edge[i].push_back(j);
            }
        }
    }
    bfs(s,e);
    reverse(e);
}