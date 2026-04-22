#include <bits/stdc++.h>

using namespace std;

int n,m;

int mp[1200][1200];

priority_queue<int> pq;
int mmx = 0;
int mmn = 1000000100;

pair<int,int> coor[1000000100];

int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> mp[i][j];
        }
    }
    for(int i=0;i<n;i++){
        sort(mp[i],mp[i]+m);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            coor[mp[i][j]] = {i,j};
        }
    }
    for(int i=0;i<n;i++){
        mmx = max(mmx,mp[i][0]);
        pq.push(-mp[i][0]);
    }
    while(1){
        mmn = min(mmn,mmx + pq.top());
        int ni = coor[-pq.top()].first;
        int nj = coor[-pq.top()].second + 1;
        if(nj >= m){
            break;
        }
        pq.pop();
        mmx = max(mmx,mp[ni][nj]);
        pq.push(-mp[ni][nj]);
    }
    cout << mmn;
}