#include <bits/stdc++.h>

using namespace std;

string s;
string t;

int main(){
    cin >> s;
    cin >> t;
    while(t.length() != s.length()){
        if(t[t.length()-1] == 'A'){
            t.pop_back();
        }else{
            t.pop_back();
            reverse(t.begin(),t.end());
        }
    }
    if(t == s){
        cout << 1;
    }else{
        cout << 0;
    }
}