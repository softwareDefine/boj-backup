#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> vc;
long long cnt;

void go(int now){
    int pos = 1;
    if(!vc.empty()){
        pos = vc.back() + 1;
    }
    for (int i = pos; i <= n * n; i++){
        // 올바른 좌표 계산 (1부터 시작하므로 -1)
        int r = (i - 1) / n;
        int c = (i - 1) % n;
        bool valid = true;
        for(auto &j : vc){
            int rj = (j - 1) / n;
            int cj = (j - 1) % n;
            // 같은 행, 열 또는 대각선 충돌 검사
            if(r == rj || c == cj || abs(r - rj) == abs(c - cj)){
                valid = false;
                break;
            }
        }
        if(valid){
            if(now == n){
                cnt++;
                // 여기서 바로 return하지 않고 현재 for문을 계속 진행해야 함
                continue;
            }
            vc.push_back(i);
            go(now + 1);
            vc.pop_back();
        }
    }
}

int main(){
    cin >> n;
    go(1);
    cout << cnt;
    return 0;
}
