#include <bits/stdc++.h>

using namespace std;

int n,m,l;
vector<int> shot;
vector<pair<int,int>> coor;
int cnt;

int main(){
    cin >> m >> n >> l;
    for(int i=0;i<m;i++){
        int x;
        cin >> x;
        shot.push_back(x); 
    }
    sort(shot.begin(),shot.end());
    for(int i=0;i<n;i++){
        int x,y;
        cin >> x >> y;
        coor.push_back({x,y});
    }
    for(int i=0;i<n;i++){
        auto [x,y] = coor[i];
        auto iter = lower_bound(shot.begin(),shot.end(),x);
        if(abs(*iter - x) + y <= l){
            cnt++;
        }else if(iter - shot.begin() -1 >= 0){
            iter--;
            if(abs(*iter - x) + y <= l){
                cnt++;
            }
        }
    }
    cout << cnt;
}