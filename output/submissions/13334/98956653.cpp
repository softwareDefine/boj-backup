#include <bits/stdc++.h>

using lint = long long;
using namespace std;

int n;
vector<lint> startPoint;
vector<pair<lint,lint>> line;
priority_queue<lint> pq;
lint d;
int cnt;
int mmx;

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        lint a,b;
        cin >> a >> b;
        if(a > b){swap(a,b);}
        startPoint.push_back(a);
        line.push_back({a,b});
    }
    cin >> d;
    sort(startPoint.begin(),startPoint.end());
    sort(line.begin(),line.end(),[](auto a,auto b){
        return a.second < b.second;
    });
    lint start = 0;
    for(int i=0;i<n;i++){
        mmx = max(mmx,cnt);
        if(line[i].second <= startPoint[start] + d){
            pq.push(-line[i].first);
            cnt++;
        }else{
            int before = startPoint[start];
            while(before==startPoint[start]){
                start++;
            }
            if(!pq.empty() && -(pq.top()) < startPoint[start]){
                cnt--;
            }
            if(line[i].second <=startPoint[start] + d){
                cnt++;
            }
        }
    }
    mmx = max(mmx,cnt);
    cout << mmx;
}