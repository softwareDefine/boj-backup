#include <bits/stdc++.h>

using lint = long long;
using namespace std;

int n;
vector<lint> startPoint;
vector<pair<lint,lint>> line;
priority_queue<lint> pq;

lint d;
int cnt;
lint mmx;

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
    sort(line.begin(),line.end(),[](auto a,auto b){
        return a.second < b.second;
    });
    lint start = 0;
    for(int i=0;i<line.size();i++){
        pq.push(-line[i].first);
        while(!pq.empty() && -pq.top() < line[i].second - d){
            pq.pop();
        }
        mmx = max(mmx,lint(pq.size()));
    }
    cout << mmx;
}