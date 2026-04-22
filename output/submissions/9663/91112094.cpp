#include <iostream>
#include <set>
#include <vector>
#include <cmath>
using namespace std;

int n;
long long cnt = 0;
set<pair<int,int>> avail; // 전역으로 전체 좌표를 저장

void solve(int placed) {
    if(placed == n) { // n개의 퀸을 모두 배치하면 해를 찾은 것
        cnt++;
        return;
    }
    // 현재 avail에 있는 좌표들 중 하나씩 선택하기 위해 복사
    vector<pair<int,int>> candidates(avail.begin(), avail.end());
    for(auto p : candidates) {
        // 이미 다른 분기에서 제거되어 avail에 없으면 건너뛰기
        if(avail.find(p) == avail.end()) continue;
        
        vector<pair<int,int>> removed; // 이번 분기에서 제거한 좌표들을 저장
        
        // avail에서 p에 의해 공격받는 모든 좌표(행, 열, 대각선)를 제거
        for(auto it = avail.begin(); it != avail.end(); ) {
            if(it->first == p.first || it->second == p.second ||
               abs(it->first - p.first) == abs(it->second - p.second)) {
                removed.push_back(*it);
                it = avail.erase(it);
            } else {
                ++it;
            }
        }
        
        // p에 퀸을 놓았다고 가정하고 다음 퀸 배치
        solve(placed + 1);
        
        // 백트래킹: 제거했던 좌표들을 복원
        for(auto &coord : removed) {
            avail.insert(coord);
        }
    }
}

int main(){
    cin >> n;
    // 1,1부터 n,n까지 모든 좌표를 avail에 삽입 (1-indexed)
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            avail.insert({i, j});
        }
    }
    solve(0);
    cout << cnt;
    return 0;
}
