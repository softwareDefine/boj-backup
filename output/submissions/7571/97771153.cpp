#include <bits/stdc++.h>

using namespace std;


int n,m;
int row[11000];
int column[11000];
int ans;

int main(){
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int r,c;
        cin >> r >> c;
        row[r]++;
        column[c]++;
    }
    int now = 0;
    int total = 0;
    int mmn = 999999;
    int mmni = 0;
    for(int i=1;i<=n;i++){
        total += (i-1)*row[i];
    }
    for(int i=1;i<=n;i++){
        now += row[i];
        if(total  < mmn){
            mmn = total;
            mmni = i;
        }
        total+=now - (m-now);
    }
    //mmni = min(max(1,mmni),n);
    //cout << mmni << ' ';
    for(int i=1;i<=n;i++){
        ans += abs(mmni-i)*row[i];
    }
    now = 0;
    total = 0;
    mmn = 999999;
    mmni = 0;
    for(int i=1;i<=n;i++){
        total += (i-1)*column[i];
    }
    for(int i=1;i<=n;i++){
        now += column[i];
        if(total  < mmn){
            mmn = total;
            mmni = i;
        }
        
        total+=now - (m-now);
    }
    for(int i=1;i<=n;i++){
        ans += abs(mmni-i)*column[i];
    }
    //cout << mmni << '\n';
    cout << ans;
}