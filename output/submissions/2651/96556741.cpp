#include <bits/stdc++.h>

using namespace std;

long long t,n;
long long meter[200];
long long checkTime[200];
long long dp[200];
vector<long long> vc;
long long before[200];

int main()
{
    cin >> t;
    cin >> n;
    for(int i=1;i<=n+1;i++){
        cin >> meter[i];
        dp[i] = 99999999999999;
    }
    for(int i=1;i<=n;i++){
        cin >> checkTime[i];
    }
    for(int i=0;i<=n+1;i++){
        long long sum = 0;
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
        long long now = n+1;
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