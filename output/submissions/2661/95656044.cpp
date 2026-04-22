#include <bits/stdc++.h>

using namespace std;

int n;
int chk;
string str;
string ans;

void go(int len){
    if(len >= n){
        if(!chk){
         chk =1;
         ans=str;   
        }
        return;
    }
    str.push_back('0');
    for(int i=0;i<3;i++){
        str[len] = '1' + i;
        int flag = 0;
        for(int k=1;k<=(len+1)/2;k++){
            if(str.substr(len+1 - k*2,k) == str.substr(len+1 - k,k)){
                flag =1;
                break;
            }
        }
        if(!flag){
            go(len+1);
        }
    }
    str.pop_back();
}

int main(){
    cin >> n;
    go(0);
    cout << ans;
}