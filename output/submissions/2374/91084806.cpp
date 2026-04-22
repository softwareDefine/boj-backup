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
        long long mmn = 99999999999999;
        while(!tower.empty() && now >= tower.top()){
            if(mmn > tower.top()){
                mmn = tower.top();
                sum += now-tower.top();
            }
            tower.pop();
        }
        tower.push(now);
    }
    long long bef = -1;
    while(!tower.empty()){
        if(bef == -1) {bef = tower.top();}
        else{
            sum += abs(tower.top()-bef);
           bef = tower.top();
        }
        tower.pop();
    }
    cout << sum;
}