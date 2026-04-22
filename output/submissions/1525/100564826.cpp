#include <bits/stdc++.h>

using namespace std;

map<string,int> mp;
queue<pair<string,int>> qu;

int main(){
    string st = "";
    for(int i = 0; i < 3;i++){
        for(int j = 0; j < 3;j++){
            char ch;
            cin >> ch;
            st += ch;
        }
    }
    qu.push({st, 0});
    while(!qu.empty()){
        auto &[now, cnt] = qu.front();
        qu.pop();
        if(now == "123456780"){
            cout << cnt;
            return 0;
        }
        string next = now;
        int idx = -1;
        for(int i = 0; i < 9; i++){
            if(now[i] == '0'){
                idx = i;
                break;
            }
        }
        if(idx - 3 >= 0){
            swap(next[idx], next[idx-3]);
            if(mp.find(next) == mp.end()){
                qu.push({next,cnt+1});
                mp[next] = cnt+1;
            }
            swap(next[idx], next[idx-3]);
        }
        if(idx - 1 >= 0){
            swap(next[idx], next[idx-1]);
            if(mp.find(next) == mp.end()){
                qu.push({next,cnt+1});
                mp[next] = cnt+1;
            }
            swap(next[idx], next[idx-1]);
        }
        if(idx + 1 < 9){
            swap(next[idx], next[idx+1]);
            if(mp.find(next) == mp.end()){
                qu.push({next,cnt+1});
                mp[next] = cnt+1;
            }
            swap(next[idx], next[idx+1]);
        }
        if(idx + 3 < 9){
            swap(next[idx], next[idx+3]);
            if(mp.find(next) == mp.end()){
                qu.push({next,cnt+1});
                mp[next] = cnt+1;
            }
            swap(next[idx], next[idx+3]);
        }
    }
    
    cout << -1;
    return 0;
}