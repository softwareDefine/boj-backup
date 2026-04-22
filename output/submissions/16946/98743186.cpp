#include <bits/stdc++.h>

using namespace std;

int n,m;

int group[2000][2000];
int ans[2000][2000];
string mp[2000];
int chker[2000000];
vector<int> added;
int cnt = 0;

void bfs(int si,int sj){
    queue<pair<int,int>> qu;
    int res = 1;
    group[si][sj] = ++cnt;
    qu.push({si,sj});
    while(!qu.empty()){
        int i = qu.front().first;
        int j = qu.front().second;
        qu.pop();
        if(i-1>=0 && mp[i-1][j] != '1' &&!(group[i-1][j])){
            res++;
            group[i-1][j] = cnt;
            qu.push({i-1,j});
        }
        if(i+1<n && mp[i+1][j] != '1' &&!(group[i+1][j])){
            res++;
            group[i+1][j] = cnt;
            qu.push({i+1,j});
        }
        if(j-1>=0 && mp[i][j-1] != '1' &&!(group[i][j-1])){
            res++;
            group[i][j-1] = cnt;
            qu.push({i,j-1});
        }
        if(j+1<m && mp[i][j+1] != '1' &&!(group[i][j+1])){
            res++;
            group[i][j+1] = cnt;
            qu.push({i,j+1});
        }
    }
    chker[cnt] = res;
}

bool find(int myone){
    for(auto element : added){
        if(myone == element){
            return 0;
        }
    }
    return 1;
}

int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> mp[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mp[i][j] =='0' && !(group[i][j])){
                bfs(i,j);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mp[i][j] == '1'){
                if(i-1 >=0 && find(group[i-1][j])){
                    added.push_back(group[i-1][j]);
                    ans[i][j] += chker[group[i-1][j]];
                }
                if(j-1 >=0 && find(group[i][j-1])){
                    added.push_back(group[i][j-1]);
                    ans[i][j] += chker[group[i][j-1]];
                }
                if(i+1 < n && find(group[i+1][j])){
                    added.push_back(group[i+1][j]);
                    ans[i][j] += chker[group[i+1][j]];
                }
                if(j+1 < m && find(group[i][j+1])){
                    added.push_back(group[i][j+1]);
                    ans[i][j] += chker[group[i][j+1]];
                }
                ans[i][j] += 1;
                added.clear();
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << (ans[i][j])%10; 
        }
        cout << '\n';
    }
}