#include <bits/stdc++.h>

using namespace std;

int n;

vector<string> slot;
int mmx = 0;
int ans = 10000000;
int res1;
int res2;

void preprocessing(){
    int m = slot.size(), j = 0;
    vector<int> pi(m+1);
    pi[0] = 0;
    for(int i = 1;i<m;i++){
        while(j > 0 && slot[i] != slot[j]){
            j = pi[j-1];
        }
        if(slot[i] == slot[j]){
            pi[i] = ++j;
        }else{
            pi[i] = 0;
        }
        mmx = max(mmx,i-pi[i]+1);
        if(ans > mmx+m-i-1){
            res1 = m-i-1;
            res2 = mmx;
            ans = mmx+m-i-1;
        }
    }
    if(m == 1){
        res1 = 0;
        res2 = 1;
    }
    cout << res1 << ' ' << res2;
    return;
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        string str;
        cin >> str;
        slot.push_back(str);
    }
    reverse(slot.begin(),slot.end());
    preprocessing();
}