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
        if(len > 0 || str[len-1] != str[len]){
             int flag = 0;
            for(int k=1;k<=(len+1)/2;k++){
                bool same = true;
                for(int i = 0; i < k; i++){
                    if(str[len - i] != str[len - k - i]){
                        same = false;
                        break;
                    }
                }
                if(same){
                    flag = 1;
                    break;
                }
            }
            if(!flag){
                go(len+1);
            }   
        }
    }
    str.pop_back();
}

int main(){
    cin >> n;
    go(0);
    cout << ans;
}