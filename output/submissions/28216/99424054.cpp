#include <bits/stdc++.h>

using lint = long long;
using namespace std;

vector<pair<int,lint>> row[210000];
vector<lint> pressedrow[210000];
vector<pair<int,lint>> column[210000];
vector<lint> pressedcolumn[210000];

int n, q;

int nx = 1, ny = 1;

lint ans;

int main(){
    cin >> n >> q;
    for(int i=0;i<n;i++){
        int x, y, w;
        cin >> x >> y >> w;
        row[y].push_back({x, w});
        column[x].push_back({y, w});
    }
    for(int i=0;i <= 200000;i++){
        row[i].push_back({0, 0});
        row[i].push_back({210000, 0});
        sort(row[i].begin(), row[i].end());
        int stackedSum = 0;
        for(auto [cord, weight] : row[i]){
            int pressedCord = lower_bound(row[i].begin(), row[i].end(), cord, [](auto p, int val){
                return p.first < val;
            }) - row[i].begin();
            stackedSum += weight;
            pressedrow[i].push_back(stackedSum);
        }
        column[i].push_back({0, 0});
        column[i].push_back({210000, 0});
        sort(column[i].begin(), column[i].end());
        stackedSum = 0;
        for(auto [cord, weight] : column[i]){
            int pressedCord = lower_bound(column[i].begin(), column[i].end(), cord, [](auto p, int val){
                return p.first < val;
            }) - column[i].begin();
            stackedSum += weight;
            pressedcolumn[i].push_back(stackedSum);
        }
    }
    while(q--){
        int d, v;
        cin >> d >> v;
        switch(d){
            case 0:{
                int start = lower_bound(row[ny].begin(), row[ny].end() , nx + 1, [](auto p, int val){
                    return p.first < val;
                }) - row[ny].begin();
                int end = upper_bound(row[ny].begin(), row[ny].end() , nx + v , [](int val,auto p){
                    return p.first > val;
                }) - row[ny].begin();
                ans += pressedrow[ny][end-1] - pressedrow[ny][start-1];
                nx += v;
                break;
            }
            case 1:{
                int start = lower_bound(column[nx].begin(), column[nx].end() , ny+1, [](auto p, int val){
                    return p.first < val;
                }) - column[nx].begin();
                int end = upper_bound(column[nx].begin(), column[nx].end() , ny + v , [](int val, auto p){
                    return p.first > val;
                }) - column[nx].begin();
                ans += pressedcolumn[nx][end-1] - pressedcolumn[nx][start-1];
                ny += v;
                break;
            }
            case 2:{
                int start = lower_bound(row[ny].begin(), row[ny].end() , nx - v , [](auto p, int val){
                    return p.first < val;
                }) - row[ny].begin();
                int end = lower_bound(row[ny].begin(), row[ny].end() , nx , [](auto p, int val){
                    return p.first < val;
                }) - row[ny].begin();
                ans += pressedrow[ny][end-1] - pressedrow[ny][start-1];
                nx -= v;
                break;}
            case 3:{
                int start = lower_bound(column[nx].begin(), column[nx].end() , ny - v, [](auto p, int val){
                    return p.first < val;
                }) - column[nx].begin();
                int end = lower_bound(column[nx].begin(), column[nx].end() , ny , [](auto p, int val){
                    return p.first < val;
                }) - column[nx].begin();
                ans += pressedcolumn[nx][end-1] - pressedcolumn[nx][start-1];
                ny -= v;
                break;
            }
        }
    }
    cout << ans;
}