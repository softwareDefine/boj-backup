#include <bits/stdc++.h>

using namespace std;

int dp[110];
string str;

int main(){
    cin >> str;
    dp[0] =1;
    for(int i=0;i<str.size();i++){
        int twoword = 99;
        if(i != str.size()-1){ twoword = (str[i]-'0')*10 + str[i+1]-'0';}
        if(twoword < 35){dp[i+2] += dp[i];}
        dp[i+1] += dp[i];
    }
    cout << dp[str.size()];
}