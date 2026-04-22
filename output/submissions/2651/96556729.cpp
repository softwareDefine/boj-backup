#include <bits/stdc++.h>

using namespace std;

int t,n;
int meter[200];
int checkTime[200];
int dp[200];
vector<int> vc;
int before[200];

int main()
{
    cin >> t;
    cin >> n;
    for(int i=1;i<=n+1;i++){
        cin >> meter[i];
        dp[i] = 2147483647;
    }
    for(int i=1;i<=n;i++){
        cin >> checkTime[i];
    }
    for(int i=0;i<=n+1;i++){
        int sum = 0;
        for(int j=i+1;j<=n+1;j++){
            sum += meter[j]; 
            if(sum > t){
                break;
            }
            if(dp[j] > dp[i] + checkTime[j]){
                dp[j] = dp[i] + checkTime[j];
                before[j] = i;
            }
        }
    }
    cout << dp[n+1];
    if(dp[n+1]){
        cout << '\n';
        int now = n+1;
        while(before[now]){
            vc.push_back(before[now]);
            now = before[now];
        }
        cout << vc.size() << '\n';
        reverse(vc.begin(),vc.end());
        for(auto i : vc){
            cout << i << ' ';
        }
    }
    return 0;
}