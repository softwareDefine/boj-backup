#include <bits/stdc++.h>

using namespace std;

typedef struct{
  int people;
  int dad;
  int mom;
  int hyun;
  int cnt;
}Node;

queue<Node> qu;

int n;
int dp[3][150][150][150];

vector<int> dir[3];
int idxend[3];

int ans = 999999999;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 150; j++){
            for(int k = 0; k < 150; k++){
                for(int l = 0; l < 150; l++){
                    dp[i][j][k][l] = 999999999;
                }
            }
        }
    }
    cin >> n;
    for(int i = 0; i < 3; i++){
        int pi;
        cin >> pi;
        idxend[i] = pi;
        dir[i].resize(200);
        for(int j = 1; j <= pi; j++){
            cin >> dir[i][j];
            dir[i][j] -= 1;
        }
    }
    qu.push({0, 0, 0, 0});
    while(!qu.empty()){
        auto [people, dad, mom, hyun, cnt] = qu.front();
        int now;
        qu.pop();
        //cout << people << ' ' << dad << ' ' << mom << ' ' << hyun << ' ' << cnt << '\n';
        if(dad == idxend[0] && mom == idxend[1] && hyun == idxend[2]){
            ans = min(ans, cnt);
            continue;
        }
        if( people == 0 ){
            now = dir[people][dad];
            for(int mv = 0; mv < 3; mv++){
                int next;
                if( mv == 0 && dad + 1 <= idxend[0] && dp[mv][dad+1][mom][hyun] > cnt + min(abs(now-next),n-abs(now-next))){
                    next = dir[mv][dad+1];
                    qu.push({mv, dad+1, mom, hyun, cnt + min(abs(now-next),n-abs(now-next))});
                    dp[mv][dad+1][mom][hyun] = min(dp[mv][dad+1][mom][hyun], cnt + min(abs(now-next),n-abs(now-next)));
                }else if(mv == 1 && mom + 1 <= idxend[1] && dp[mv][dad][mom+1][hyun] > cnt + min(abs(now-next),n-abs(now-next))){
                    now = (now + n/3)%n;
                    next = dir[mv][mom+1];
                    qu.push({mv, dad, mom+1, hyun, cnt + min(abs(now-next),n-abs(now-next))});
                    dp[mv][dad][mom+1][hyun] = min(dp[mv][dad][mom+1][hyun], cnt + min(abs(now-next),n-abs(now-next)));
                }else{
                    if(hyun + 1 <= idxend[2] && dp[mv][dad][mom][hyun+1] > cnt + min(abs(now-next),n-abs(now-next))){
                        now = (now + (n/3)*2)%n;
                        next = dir[mv][hyun+1];
                        qu.push({mv, dad, mom, hyun+1, cnt + min(abs(now-next),n-abs(now-next))});
                        dp[mv][dad][mom][hyun+1] = min(dp[mv][dad][mom][hyun+1], cnt + min(abs(now-next),n-abs(now-next)));
                    }
                }
            }
        }else if( people == 1 ){
            now = (dir[people][mom] - (n/3) + n )%n;
            for(int mv = 0; mv < 3; mv++){
                int next;
                if( mv == 0 && dad + 1 <= idxend[0] && dp[mv][dad+1][mom][hyun] > cnt + min(abs(now-next),n-abs(now-next))){
                    next = dir[mv][dad+1];
                    qu.push({mv, dad+1, mom, hyun, cnt + min(abs(now-next),n-abs(now-next))});
                    dp[mv][dad+1][mom][hyun] = min(dp[mv][dad+1][mom][hyun], cnt + min(abs(now-next),n-abs(now-next)));
                }else if(mv == 1 && mom + 1 <= idxend[1] && dp[mv][dad][mom+1][hyun] > cnt + min(abs(now-next),n-abs(now-next))){
                    now = (now + n/3)%n;
                    next = dir[mv][mom+1];
                    qu.push({mv, dad, mom+1, hyun, cnt + min(abs(now-next),n-abs(now-next))});
                    dp[mv][dad][mom+1][hyun] = min(dp[mv][dad][mom+1][hyun], cnt + min(abs(now-next),n-abs(now-next)));
                }else{
                    if(hyun + 1 <= idxend[2] && dp[mv][dad][mom][hyun+1] > cnt + min(abs(now-next),n-abs(now-next))){
                        now = (now + (n/3)*2)%n;
                        next = dir[mv][hyun+1];
                        qu.push({mv, dad, mom, hyun+1, cnt + min(abs(now-next),n-abs(now-next))});
                        dp[mv][dad][mom][hyun+1] = min(dp[mv][dad][mom][hyun+1], cnt + min(abs(now-next),n-abs(now-next)));
                    }
                }
            }
        }else{
            now = (dir[people][hyun] - (n/3)*2 + n )%n;
            for(int mv = 0; mv < 3; mv++){
                int next;
                if( mv == 0 && dad + 1 <= idxend[0] && dp[mv][dad+1][mom][hyun] > cnt + min(abs(now-next),n-abs(now-next))){
                    next = dir[mv][dad+1];
                    qu.push({mv, dad+1, mom, hyun, cnt + min(abs(now-next),n-abs(now-next))});
                    dp[mv][dad+1][mom][hyun] = min(dp[mv][dad+1][mom][hyun], cnt + min(abs(now-next),n-abs(now-next)));
                }else if(mv == 1 && mom + 1 <= idxend[1] && dp[mv][dad][mom+1][hyun] > cnt + min(abs(now-next),n-abs(now-next))){
                    now = (now + n/3)%n;
                    next = dir[mv][mom+1];
                    qu.push({mv, dad, mom+1, hyun, cnt + min(abs(now-next),n-abs(now-next))});
                    dp[mv][dad][mom+1][hyun] = min(dp[mv][dad][mom+1][hyun], cnt + min(abs(now-next),n-abs(now-next)));
                }else{
                    if(hyun + 1 <= idxend[2] && dp[mv][dad][mom][hyun+1] > cnt + min(abs(now-next),n-abs(now-next))){
                        now = (now + (n/3)*2)%n;
                        next = dir[mv][hyun+1];
                        qu.push({mv, dad, mom, hyun+1, cnt + min(abs(now-next),n-abs(now-next))});
                        dp[mv][dad][mom][hyun+1] = min(dp[mv][dad][mom][hyun+1], cnt + min(abs(now-next),n-abs(now-next)));
                    }
                }
            }
        }
    }
    cout << ans;
}