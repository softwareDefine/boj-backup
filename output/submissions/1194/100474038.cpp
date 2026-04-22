#include <bits/stdc++.h>

using namespace std;

int n, m;

typedef struct Node{
    int i;
    int j;
    int keys;
    int cnt;
}Node;

// i j keys
int visited[100][100][100];

string mp[100];

pair<int,int> nextMove[4] = {{-1,0}, {1,0} ,{0,-1}, {0,1}}; 

queue<Node> qu;

int times;

int bfs(){
    while(!qu.empty()){
        int i = qu.front().i;
        int j = qu.front().j;
        int keys = qu.front().keys;
        int cnt = qu.front().cnt;
        qu.pop();
        if(mp[i][j] == '1'){
            return cnt;
        }
        for(auto element : nextMove){
            auto &next = mp[i+element.first][j+element.second];
            int nextKeys = keys;
            if(i+element.first < n && i+element.first >= 0 && j+element.second < m && j+element.second >= 0 && next != '#'){
                if(next >= 'a' && next <= 'z'){
                    nextKeys |= (1<<(next-'a'));
                }
                if(visited[i+element.first][j+element.second][nextKeys] > cnt+1){
                    if(mp[i+element.first][j+element.second] >= 'A' && mp[i+element.first][j+element.second] <= 'Z'){
                        if(nextKeys & (1<<(next-'A'))){
                            visited[i+element.first][j+element.second][nextKeys] = cnt+1;
                            qu.push({i+element.first,j+element.second,nextKeys,cnt+1});
                        }
                    }else{
                        visited[i+element.first][j+element.second][nextKeys] = cnt+1;
                        qu.push({i+element.first,j+element.second,nextKeys,cnt+1});
                    }
                }
            }
        }
    }
    return -1;
}

int main()
{
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            for(int k=0;k<100;k++){
                visited[i][j][k] = 99999999;
            }
        }
    }
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> mp[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mp[i][j] == '0'){
                qu.push({i,j,0,0});
                mp[i][j] = '.';
            }
        }
    }
    cout << bfs();
    return 0;
}