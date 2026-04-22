#include <bits/stdc++.h>

using namespace std;

int n;

pair<int,int> coor[300000];
vector<pair<int,int>> xline;
vector<pair<int,int>> yline;
int mmx;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i=0;i<n;i++){
        int x,y;
        cin >> x >> y;
        coor[i] = coor[n+i] = {x,y};
    }
    for(int i=0;i<n;i++){
        if(coor[i+1].first == coor[i].first){
            if(coor[i].second > coor[i+1].second){
                yline.push_back({coor[i+1].second,coor[i].second});
            }else{
                yline.push_back({coor[i].second,coor[i+1].second});
            }
        }else{
            if(coor[i].first > coor[i+1].first){
                xline.push_back({coor[i+1].first,coor[i].first});
            }else{
                xline.push_back({coor[i].first,coor[i+1].first});
            }
        }
    }
    sort(xline.begin(),xline.end(),[](auto a,auto b){
        if(a.second == b.second){return a.second > b.second;}
        return a.first < b.first;
    });
    int now = xline[0].second;
    int cnt = 0;
    for(int i=0;i<xline.size();i++){
        if(now > xline[i].first){
            cnt++;
        }else{
            mmx = max(mmx,cnt);
            cnt = 0;
            now = xline[i].second;
        }
    }
    mmx = max(mmx,cnt);
    cnt = 0;
    sort(yline.begin(),yline.end(),[](auto a,auto b){
        if(a.second == b.second){return a.second > b.second;}
        return a.first < b.first;
    });
    now = yline[0].second;
    cnt = 0;
    for(int i=0;i<yline.size();i++){
        if(now > yline[i].first){
            cnt++;
        }else{
            mmx = max(mmx,cnt);
            cnt = 0;
            now = yline[i].second;
        }
    }
    mmx = max(mmx,cnt);
    cout << mmx;
}