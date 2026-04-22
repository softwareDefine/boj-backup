#include <bits/stdc++.h>

using namespace std;
stack<long long> tower;
int n;
long long sum;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i=0;i<n;i++){
        long long now;
        cin >> now;
        while(!tower.empty() && now >= tower.top()){
            sum += now-tower.top();
            tower.pop();
        }
        tower.push(now);
    }
     long long  bef = -1;
    
    cout << sum;
}