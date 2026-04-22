#include <bits/stdc++.h>

using namespace std;
string str;
int t;

int go(int start,int end,int used){
    if(start >= end){
        return 0;
    }
    if(str[start] == str[end]){
        return go(start+1,end-1,used);
    }else if(str[start] != str[end]){
        if(!used){
            return min(go(start+1,end,1)+1,go(start,end-1,1)+1);
        }else{
            return 1;
        }
    }
}

int main(){
    cin >> t;
    while(t--){
        cin >> str;
        cout << go(0,str.size()-1,0) << '\n';
    }
}