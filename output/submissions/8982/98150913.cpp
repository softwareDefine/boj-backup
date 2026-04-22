#include <bits/stdc++.h>

using namespace std;

int n;

vector<pair<int,int>> point;
vector<pair<int,int>> block;
vector<pair<int,int>> revised;
int k;
bool hole[5000];

map<pair<int,int>,pair<int,int>> mp;

int sum;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i=0;i<n;i++){
        int x,y;
        cin >> x >> y;
        point.push_back({x,y});
    }
    cin >> k;
    for(int i=0;i<k;i++){
        int x,y, nx,ny;
        cin >> x >> y >> nx >> ny;
        mp[{x,y}] = {nx,ny};
    }
    int nowx = 0,nowy = 0;
    for(int i=1;i<n;i++){
        // 세로줄 증감
        if(!(i%2)){
            nowx += point[i].first - point[i-1].first;
            block.push_back({point[i].first - point[i-1].first,nowy});
            revised.push_back({point[i].first - point[i-1].first,nowy});
            if(mp.find(point[i-1]) != mp.end()){
                hole[block.size()-1] = 1;
            }
        }
        // 가로줄 증감
        else{
            nowy += point[i].second - point[i-1].second;
        }
    }
    for(int i=0;i<block.size();i++){
        if(hole[i]){
            int now = block[i].second;
            int j = i;
            while(j >= 0){
                now = min(now,block[j].second);
                revised[j].second = min(revised[j].second,block[j].second-now);
                j--;
            }
            j = i+1;
            while(j < n){
                now = min(now,block[j].second);
                revised[j].second = min(revised[j].second,block[j].second-now);
                j++;
            }
        }
    }
    for(auto [wide,height] : revised){
        //cout << wide << ' ' << height << '\n';
        sum += wide*height;
    }
    cout << sum;
}