#define x first
#define y second
#include<bits/stdc++.h>

using namespace std;
using point = pair<int,int>;

int n;

vector<pair<point,point>> square;
vector<int> ansvc;

int used[100];
int ans = 0,tmp;

// 1. 백트랙킹을 하되 주변이 0( 방문한 곳 중 사용 안함 )이거나 연결된게 없다면 확정해도 된다.
// 2. 대각선을 왼쪽아래 오른쪽 위로 통일해라
// 3. 그 후 4점을 모두 만든후 한 사각형을 잡아서 그 안에 점이 들어오는지 판별해라

bool intersect(int a, int b){
    int ax1 = min(square[a].first.x, square[a].second.x);
    int ax2 = max(square[a].first.x, square[a].second.x);
    int ay1 = min(square[a].first.y, square[a].second.y);
    int ay2 = max(square[a].first.y, square[a].second.y);

    int bx1 = min(square[b].first.x, square[b].second.x);
    int bx2 = max(square[b].first.x, square[b].second.x);
    int by1 = min(square[b].first.y, square[b].second.y);
    int by2 = max(square[b].first.y, square[b].second.y);

    // "떨어져 있음"이 성립할 조건 (엄격 <) : 닿으면 금지라서 < 여야 함
    bool separated = (ax2 < bx1) || (bx2 < ax1) || (ay2 < by1) || (by2 < ay1);

    return !separated; // separated가 아니면 겹치거나/닿음 => 금지
}

void go(int now){
    if(now == n){
        if(ans < tmp){
            ans = tmp;
            ansvc.clear();
            for(int i = 0; i < n; i++){
                if(used[i]){
                    ansvc.push_back(i+1);
                }
            }
        }
        return;
    }
    int flag = 0, impossible = 0;
    for(int i = 0; i < n; i++){
        if((i < now && used[i] && (intersect(i, now) || intersect(now, i)))){
            impossible = 1;
            flag = 1;
        }
        if((i > now && (intersect(i, now) || intersect(now, i)))){
            flag = 1;
            break;
        }
    }
    // 내가 사용하는 경우
    if(!impossible){
        tmp += (now+1);
        used[now] = 1;
        go(now+1);
        tmp -= (now+1);
        used[now] = 0;
    }
    // 내가 사용하지 않는 경우
    if(flag){
        used[now] = 0; 
        go(now+1);
    }
}

int main(){
    cin >> n;
    square.resize(n);
    for(auto &[a, b] : square){
        cin >> a.first >> a.second >> b.first >> b.second;
        if(a > b){
            swap(a,b);
        }
        if(a.second > b.second){
            swap(a.second, b.second);
        }
    }
    go(0);
    cout << ansvc.size() << '\n';
    for(auto element : ansvc){
        cout << element << ' ';
    }
}