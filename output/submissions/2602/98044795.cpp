#include <bits/stdc++.h>

using namespace std;

string str;
string devil,heaven;

// 몇번째 위치, 밟은 돌의 개수 , (악,천)
int dp[200][30][2];
int sum;

int main(){
    cin >> str;
    cin >> devil;
    cin >> heaven;
    for(int i=0;i<heaven.length();i++){
        for(int j=0;j<str.length();j++){
            if(str[j] == devil[i]){
                if(j == 0){
                    dp[i][0][0] = 1;
                }
                for(int k=i+1;k<heaven.length();k++){
                    if(str[j+1] == heaven[k]){
                        dp[k][j+1][1] += dp[i][j][0];
                    }
                }
            }
            if(str[j] == heaven[i]){
                if(j == 0){
                    dp[i][0][1] = 1;
                }
                for(int k=i+1;k<heaven.length();k++){
                    if(str[j+1] == devil[k]){
                        dp[k][j+1][0] += dp[i][j][1];
                    }
                }
            }
        }
    }
    for(int i=0;i<heaven.length();i++){
        sum += dp[i][str.length()-1][0];
        sum += dp[i][str.length()-1][1];
    }
    cout << sum;
}