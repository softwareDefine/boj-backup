#include <bits/stdc++.h>

using lint = long long;
using namespace std;

int n;
vector<lint> startPoint;
vector<pair<lint,lint>> line;
priority_queue<lint> pq;

//priority_queue<pair<lint,lint>, vector<pair<lint,lint>>, greater<pair<lint,lint>>> pq2;
lint d;
int cnt;
int mmx;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i=0;i<n;i++){
        lint a,b;
        cin >> a >> b;
        if(a > b){swap(a,b);}
        line.push_back({a,b});
    }
    cin >> d;
    for(int i=0;i<line.size();){
        if(line[i].second - line[i].first > d){
            line.erase(line.begin()+i);
            continue;
        }
        startPoint.push_back(line[i].first);
        i++;
    }
    sort(startPoint.begin(),startPoint.end());
    sort(line.begin(),line.end(),[](auto a,auto b){
        return a.second < b.second;
    });
    lint start = 0;
    for(int i=0;i<line.size();i++){
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
                pq.pop();
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