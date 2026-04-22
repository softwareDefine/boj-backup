#include <bits/stdc++.h>

using lint = long long;
using namespace std;

int n,k;

// 총 매대시간, 몇번째 계산대
priority_queue<pair<lint,lint>> pq;
// 시간, 몇번째 나오는 지
vector<pair<pair<lint,lint>,lint>> ans;

vector<pair<lint,lint>> order;

lint sum;

int main(){
    cin >> n >> k;
    for(int i=0;i<n;i++){
        int id,w;
        cin >> id >> w;
        order.push_back({id,w});
    }
    for(int i=1;i<=k;i++){
        pq.push({0,-i});
    }
    for(auto [id,w] : order){
        int now = -pq.top().first;
        int loc = -pq.top().second;
        ans.push_back({{now+w,loc},id});
        pq.pop();
        pq.push({-(now+w),-loc});
    }
    sort(ans.begin(),ans.end(),[](auto a,auto b){
        if(a.first.first == b.first.first){return a.first.second > b.first.second;}
        return a.first.first < b.first.first;
    });
    for(int i=0;i<ans.size();i++){
        sum += (i+1)*ans[i].second;
    }
    cout << sum;
}