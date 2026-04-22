#include <bits/stdc++.h>

using namespace std;

int n, m;
int k;

map<string,int> mp;

int mmx;

int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        string str;
        cin >> str;
        mp[str]++;
    }
    cin >> k;
    for(auto [str,res] : mp){
        int cnt = 0;
        for(int i=0;i < str.length(); i++){
            if(str[i] == '0'){
                cnt++;
            }
        }
        if(k >= cnt && !((k-cnt)%2)){
            mmx = max(mmx,res);
        }
    }
    cout << mmx;
}