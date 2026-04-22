#include <bits/stdc++.h>

using namespace std;

typedef struct brick{
    int s;
    int h;
    int w;
    int idx;
};

int n;
int dp[200][200];
pair<int,int> before[200][200];
brick arr[200];
deque<int> dq;

bool cmp(brick a,brick b){
    if(a.s == b.s){
        return a.w > b.w;
    }
    return a.s > b.s;
}

int mmx;
pair<int,int> mmxi;

int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        int s,h,w;
        cin >> arr[i].s >> arr[i].h >> arr[i].w;
        arr[i].idx = i;
    }
    sort(arr+1,arr+n+1,cmp);
    arr[0] = {999999,0,999999};
    for(int i=1;i<=n;i++){
        for(int j=0;j<=i;j++){
            dp[i][j] = dp[i-1][j];
            before[i][j] = {i-1,j};
            
        }
         for(int k=0;k<i;k++){
            if(arr[i].s < arr[k].s && arr[i].w < arr[k].w && dp[i][i] < dp[i-1][k] + arr[i].h){
                dp[i][i] = dp[i-1][k] + arr[i].h;
                before[i][i] = {i-1,k};
                if(mmx < dp[i][i]){
                    mmx = dp[i][i];
                    mmxi = {i,i};
                }
            }
        }
    }
    //cout << mmx << '\n';
    pair<int,int> i = mmxi;
    while(i.first!=0){
        if(dq.empty() || arr[i.second].idx != dq.back()){
            dq.push_back(arr[i.second].idx);
        }
        i = before[i.first][i.second];
    }
    cout << dq.size() << '\n';
    for(auto e : dq){
        cout << e << '\n';
    }
}