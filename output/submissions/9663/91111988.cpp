#include <iostream>
#include <set>
#include <cmath>
using namespace std;

int n;
long long cnt = 0;

void solve(int placed, const set<pair<int,int>> &avail) {
    if(placed == n) {  // n개의 퀸을 모두 놓았으면 해 발견
        cnt++;
        return;
    }
    // available set이 비어있으면 더 진행 불가
    if(avail.empty()) return;
    
    // avail에 남은 각 좌표에 대해 퀸을 놓는 시도
    for(auto p : avail) {
        int r = p.first, c = p.second;
        set<pair<int,int>> newAvail;
        // avail에서 현재 p에 의해 공격받지 않는 좌표들만 새 available set에 추가
        for(auto q : avail) {
            int r2 = q.first, c2 = q.second;
            if(r2 == r || c2 == c || abs(r2 - r) == abs(c2 - c)) continue;
            newAvail.insert(q);
        }
        solve(placed + 1, newAvail);
    }
}

int main(){
    cin >> n;
    set<pair<int,int>> avail;
    // 1,1부터 n,n까지 모든 좌표를 avail에 저장 (1-indexed)
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            avail.insert({i, j});
        }
    }
    solve(0, avail);
    cout << cnt;
    return 0;
}
