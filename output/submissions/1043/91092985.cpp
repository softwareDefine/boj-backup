#define fastio cin.tie(0)->sync_with_stdio(0)
#include<bits/stdc++.h>

using namespace std;

int n,m;
int nk;
int knower[100];
int parent[100];
vector<int> group[100];
int cnt;

int find(int now){
    if(parent[now] == now){
        return now;
    }
    return parent[now] = find(parent[now]);
}

int main(){
    for(int i=0;i<100;i++){
        parent[i] = i;
    }
    fastio;
    cin >> n >> m;
    cin >> nk;
    for(int i=0;i<nk;i++){
        cin >> knower[i];
    }
    for(int i=0;i<m;i++){
        int pp;
        cin >> pp;
        int onfirst;
        for(int j=0;j<pp;j++){
            int tmp;
            cin >> tmp;
            if(j == 0){
                onfirst = tmp;
                group[i].push_back(tmp);
                continue;
            }
            if(find(onfirst) != find(tmp) ){
                parent[find(onfirst)] = find(tmp);
            }
            group[i].push_back(tmp);
        }
    }
    for(int i=0;i<m;i++){
        int flg = 0;
        for(int &j : group[i]){
            for(int k=0;k<nk;k++){
                if(find(j) == find(knower[k])){
                    flg = 1;
                    break;
                }
            }
        }
        if(!flg){
            cnt++;
        }
    }
    cout << cnt;
}