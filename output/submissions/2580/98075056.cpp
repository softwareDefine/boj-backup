#include <bits/stdc++.h>

using namespace std;

int arr[20][20];
int flag;
vector<pair<int,int>> seq;

void go(int now){
    if(flag){return;}
    if(now == seq.size()){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout << arr[i][j] << ' ';
            }
            cout << '\n';
        }
        flag = 1;
        return;
    }
    auto [y,x] = seq[now];
    int finder[20] = {0, };
    int by = y/3, bx = x/3;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            finder[arr[by*3 + i][bx*3 + j]]++;
        }
    }
    for(int i=0;i<9;i++){
        finder[arr[i][x]]++;
        finder[arr[y][i]]++;
    }
    for(int i=1;i<=9;i++){
        if(!finder[i]){
            arr[y][x] = i;
            go(now+1);
            if(flag){return;}
            arr[y][x] = 0;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin >> arr[i][j];
            if(!arr[i][j]){
                seq.push_back({i,j});
            }
        }
    }
    go(0);
}
