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
    return (square[a].first.x <= square[b].first.x && square[b].first.x <= square[a].second.x && square[a].first.y <= square[b].first.y && square[b].first.y <= square[a].second.y ) || (square[a].first.x <= square[b].second.x && square[b].second.x <= square[a].second.x && square[a].first.y <= square[b].second.y && square[b].second.y <= square[a].second.y ) ;
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