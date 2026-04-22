#define fastio cin.tie(0)->sync_with_stdio(0);
#define x first
#define y second
#include <bits/stdc++.h>

using ll = long long;
using namespace std;
using point = pair<ll,ll>;

point acc[1010];
ll dp[1010][1010];
ll mmn = 99999999999;
ll mmnx;
ll mmny;
ll n,q;

inline ll dist(point bef,point aft){
    return abs(aft.x-bef.x) + abs(aft.y - bef.y);
}

void dfs(ll a, ll b,ll now){
    if (now == -1){return;}
    if(now == a){
        if(b == now-1){
            if(b==0){
                cout << 1 << '\n';
                return;
            }
            for(int i=0;i<=now-2;i++){
                if(dp[i][b] + dist(acc[i],acc[now]) == dp[now][b]){
                    dfs(i,b,now-1);
                    cout << 1 << '\n';
                    break;
                }
            }
        }else{
            if(dp[now-1][b] + dist(acc[now-1],acc[now]) == dp[now][b]){
                dfs(now-1,b,now-1);
                cout << 1 << '\n';
            }
        }
    }else if(now == b){
        if(a == now-1){
            if(a==0){
                cout << 2 << '\n';
                return;
            }
            for(int i=0;i<=now-2;i++){
                if(i == 0){
                    if(dp[a][i] + dist(acc[1009],acc[now]) == dp[a][now]){
                        dfs(a,i,now-1);
                        cout << 2 << '\n';
                        break;
                    }
                }else{
                    if(dp[a][i] + dist(acc[i],acc[now]) == dp[a][now]){
                        dfs(a,i,now-1);
                        cout << 2 << '\n';
                        break;
                    }
                }
                
            }
        }else{
            if(dp[a][now-1] + dist(acc[now-1],acc[now]) == dp[a][now]){
                dfs(a,now-1,now-1);
                cout << 2 << '\n';
            }
        }
    }
}
int main(){
    fastio;
	cin >> n >> q;	
    for(int i=1;i<=q;i++){
		cin >> acc[i].x >> acc[i].y;
	}
    for(int i=0;i<=q;i++){
        for(int j=0;j<=q;j++){
            dp[i][j] = 99999999999;
        }
    }
    acc[0] = {1,1}; //?
    acc[1009] = {n,n}; //?
    dp[1][0] = dist({1,1},acc[1]);
    dp[0][1] = dist({n,n},acc[1]);
    for(int i=2;i<=q;i++){
        for(int j=0;j<=i-1;j++){
            if(j==0){
                dp[i][j] = min(dp[i][j],dp[i-1][j] + dist(acc[i-1],acc[i]));
                dp[i][i-1] = min(dp[i][i-1],dp[j][i-1] + dist(acc[0],acc[i]));
                dp[j][i] = min(dp[j][i],dp[j][i-1] + dist(acc[i-1],acc[i]));
                dp[i-1][i] = min(dp[i-1][i],dp[i-1][j]+dist(acc[1009],acc[i]));
            }else{
                dp[i][j] = min(dp[i][j],dp[i-1][j] + dist(acc[i-1],acc[i]));
                dp[i][i-1] = min(dp[i][i-1],dp[j][i-1] + dist(acc[j],acc[i]));
                dp[j][i] = min(dp[j][i],dp[j][i-1] + dist(acc[i-1],acc[i]));
                dp[i-1][i] = min(dp[i-1][i],dp[i-1][j]+dist(acc[j],acc[i]));
            }					
        }
    }
    for(int i=q-1;i>=0;i--){
        if(dp[q][i] < mmn){
            mmn = dp[q][i];
            mmnx = q;
            mmny = i;
        }
        if(dp[i][q] < mmn){
            mmn = dp[i][q];
            mmnx = i;
            mmny = q;
        }
    }
    cout << mmn << '\n';
    dfs(mmnx,mmny,q);
}