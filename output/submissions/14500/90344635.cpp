#define fastio cin.tie(0)->sync_with_stdio(0)
#include <bits/stdc++.h>

using namespace std;

int mmx = 0;
int mp[600][600];

int main(){
    int n,m;
    cin >> n >> m;
    for(int i=6;i<=n+5;i++){
        for(int j=6;j<=m+5;j++){
            cin >> mp[i][j];
        }
    }
    for(int i=3;i<=n+5;i++){
        for(int j=3;j<=m+5;j++){
            mmx = max(mp[i][j] + mp[i][j+1] + mp[i][j+2] + mp[i][j+3],mmx);
            mmx = max(mp[i][j] + mp[i+1][j] + mp[i+2][j] + mp[i+3][j],mmx);
        }
    }
    for(int i=3;i<=n+5;i++){
        for(int j=3;j<=m+5;j++){
            mmx = max(mp[i][j] + mp[i][j+1] + mp[i+1][j] + mp[i+1][j+1],mmx);
        }
    }
    for(int i=3;i<=n+5;i++){
        for(int j=3;j<=m+5;j++){
            mmx = max(mp[i][j] + mp[i+1][j] + mp[i][j+1] + mp[i][j+2],mmx);
            mmx = max(mp[i][j+1] + mp[i-1][j] + mp[i-2][j] + mp[i][j],mmx);
            mmx = max(mp[i][j] + mp[i][j-1] + mp[i][j-2] + mp[i+1][j],mmx);
            mmx = max(mp[i][j-1] + mp[i][j] + mp[i+1][j] + mp[i+2][j],mmx);
            mmx = max(mp[i][j-1] + mp[i][j-2] + mp[i][j] + mp[i-1][j],mmx);
            mmx = max(mp[i][j-1] + mp[i-1][j] + mp[i][j] + mp[i-2][j],mmx);
            mmx = max(mp[i][j+1] + mp[i-1][j] + mp[i][j] + mp[i][j+2],mmx);
            mmx = max(mp[i][j+1] + mp[i+1][j] + mp[i][j] + mp[i+2][j],mmx);
        }
    }
    for(int i=3;i<=n+5;i++){
        for(int j=3;j<=m+5;j++){
            mmx = max(mp[i][j] + mp[i-1][j] + mp[i][j+1] + mp[i+1][j+1],mmx);
            mmx = max(mp[i+1][j] + mp[i+1][j-1] + mp[i][j+1] + mp[i][j],mmx);
            mmx = max(mp[i][j] + mp[i][j+1] + mp[i-1][j+1] + mp[i+1][j],mmx);
            mmx = max(mp[i][j] + mp[i][j-1] + mp[i+1][j] + mp[i+1][j+1],mmx);
        }
    }
    for(int i=3;i<=n+5;i++){
        for(int j=3;j<=m+5;j++){
            mmx = max(mp[i][j] + mp[i+1][j] + mp[i][j+1] + mp[i][j-1],mmx);
            mmx = max(mp[i][j] + mp[i][j-1] + mp[i-1][j] + mp[i+1][j],mmx);
            mmx = max(mp[i][j] + mp[i-1][j] + mp[i][j+1] + mp[i][j-1],mmx);
            mmx = max(mp[i][j] + mp[i-1][j] + mp[i+1][j] + mp[i][j+1],mmx);
        }
    }
    cout << mmx;
}