#include <bits/stdc++.h>

using lint = long long;
using namespace std;

lint n, l;

// 1. 각 선의 좌표마다 연결된 막대기를 MAP에 넣고
// 2. 정렬된 선에 따라 이것을 O(N) 반복문으로 계산을 한다.
// 3. dp if this is last used stick of this group what is the maximum length of this group 

vector<pair<lint,lint>> stick;

unordered_map<lint, vector<lint>> mpUp; unordered_map<lint, vector<lint>> mpDown;

lint dp[200000][2];
lint ans;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> l;
    stick.resize(n);
    for(int i = 0; i < n; i++){
        cin >> stick[i].first >> stick[i].second;
    }
    sort(stick.begin(), stick.end(), [&](auto a, auto b){
        if(min(a.first,a.second) == min(b.first, b.second)){
return a < b;
}
       return min(a.first,a.second) < min(b.first, b.second); 
    });
    for(int i = 0; i < n; i++){
        mpUp[stick[i].first].push_back(i);
        mpDown[stick[i].second].push_back(i);
        dp[i][0] = max(dp[i][0], l + abs(stick[i].first - stick[i].second));
        dp[i][1] = max(dp[i][1], l + abs(stick[i].first - stick[i].second));
    }
    for(int now = 0; now < n; now++){
        //sort(mpUp[stick[now].first].begin(),mp)
        for(auto &next : mpUp[stick[now].first]){
            if(stick[now].second < stick[next].second){
                dp[next][1] = max(dp[next][1], dp[now][0] + l + abs(stick[next].first - stick[next].second));
            }
        }
        for(auto &next : mpDown[stick[now].second]){
            if(stick[now].first < stick[next].first ){
                dp[next][0] = max(dp[next][0], dp[now][1] + l + abs(stick[next].first - stick[next].second));
            }
        }
    }
    for(int i = 0; i < n; i++){
        ans = max(ans, max(dp[i][0], dp[i][1]));   
    }
    cout << ans;
} 