#define value first
#define idx second
#include <bits/stdc++.h>

using lint = long long;
using namespace std;

lint n, k;

lint arr[110000];

deque<pair<lint,lint>> dq;

lint ans = -999999999;

int main() {
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++){
        if(dq.empty()){ans = max(ans, arr[i]); dq.push_back({arr[i], i}); continue;}
        // 기한 지난거 빼기
        if(dq.front().idx < i-k){ dq.pop_front(); }
        if(arr[i] >= 0){
            lint nxt = max(arr[i],dq.front().value + arr[i]);
            ans = max(ans, nxt);
            while(!dq.empty()){
                dq.pop_front();
            }
            dq.push_back({nxt, i});
        }else{
            lint nxt = max(arr[i],dq.front().value + arr[i]);
            ans = max(ans, nxt);
            while(!dq.empty() && dq.back().value <= nxt){
                dq.pop_back();
            }
            dq.push_back({nxt, i});
        }
        int szze = dq.size();
    }
    cout << ans;
	return 0;
}