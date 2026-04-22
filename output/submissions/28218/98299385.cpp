#include <bits/stdc++.h>

using namespace std;

int n,m,k;

int winner[400][400][2];
string mp[400];

int q;

int go(int i,int j,int turn){
    if(winner[i][j][turn%2] != -1){
        return winner[i][j][turn%2];
    }
    if(i == n-1 && j == m-1){
        //cout << turn;
        return !(turn%2);
    }
    vector<int> vc;
    if(i+1 < n && mp[i+1][j] != '#'){
        vc.push_back(go(i+1,j,turn+1));
    }
    if(j+1 < m && mp[i][j+1] != '#'){
        vc.push_back(go(i,j+1,turn+1));
    }
    for(int a=1;a<=k;a++){
        if(i+a <n && j+a <m && mp[i+a][j+a] != '#'){
            vc.push_back(go(i+a,j+a,turn+1));
        }
    }
    if(turn%2 == 0){
        for(auto my : vc){
            if(!my){
                return 0;
            }
        }
        return 1;
    }else{
        for(auto my : vc){
            if(my == 1){
                return 1;
            }
        }
        return 0;
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    for(int i=0;i<400;i++){
        for(int j=0;j<400;j++){
            winner[i][j][0] = -1;
            winner[i][j][1] = -1;
        }
    }
    cin >> n >> m >> k;
    for(int i=0;i<n;i++){
        cin >> mp[i];
    }
    cin >> q;
    for(int i=0;i<q;i++){
        int x,y;
        cin >> x >> y;
        int res = go(x-1,y-1,1);
        if(res == 1){
            cout << "First" << '\n';
        }else{
            cout << "Second" << '\n';
        }
    }
}