#include <bits/stdc++.h>

using namespace std;
stack<int> tower;
int n;
int sum;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i=0;i<n;i++){
        int now;
        cin >> now;
        while(!tower.empty() && now >= tower.top()){
            sum += now-tower.top();
            tower.pop();
        }
        tower.push(now);
    }
    long long bef = -1;
    while(!tower.empty()){
        if(bef == -1) {bef = tower.top();}
        else{
            sum += (tower.top()-bef);
          bef = tower.top();
        }
        tower.pop();
    }
    cout << sum;
}