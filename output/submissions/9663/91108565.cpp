#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int,int>> vc;
int cnt;

void go(int now){
    if(now == n+1){
        cnt++;
        return;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int chk = 0;
            for(auto &coor : vc){
                if(abs(coor.first - i) == abs(coor.second -j) || coor.first == i || coor.second == j){
                    chk = 1;
                    break;
                }
            }
            if(!chk){
                vc.push_back({i,j});
                go(now+1);
                vc.pop_back();   
            }
            
        }
        
    }
}

int main(){
    cin >> n;
    go(1);
    cout << cnt;
}