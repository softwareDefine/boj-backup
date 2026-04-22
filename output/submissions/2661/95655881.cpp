#include <bits/stdc++.h>

using namespace std;

int n;
string str;

string go(int len){
    if(len >= n){
        return str;
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
            return go(len+1);
        }
    }
}

int main(){
    cin >> n;
    cout << go(0);
}