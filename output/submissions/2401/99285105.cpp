#include <bits/stdc++.h>

using namespace std;

int n;

string str;
int cord[2000000];
string ptr[1000];

int pi[2000000];
int dp[2000000];
int main(){
    cin >> str;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> ptr[i];
    }
    int j;
    for(int t=0; t<n; t++){
        memset(pi,0,sizeof(pi));
        memset(cord,0,sizeof(cord));
        j = 0;
        for(int i=1;i<ptr[t].length();i++){
            while( j > 0 && ptr[t][i] != ptr[t][j]){
                j = pi[j-1];
            }
            if(ptr[t][i] == ptr[t][j]){
                pi[i] = ++j;   
            }
        }
        j = 0;
        for(int i=0;i<str.size();i++){
            while( j > 0 && str[i] != ptr[t][j]){
                j = pi[j-1];
            }
            if(str[i] == ptr[t][j]){
                if(j == ptr[t].size()-1){
                    cord[i-ptr[t].size()+1]=ptr[t].size();
                    j = pi[j];
                }else{
                    ++j;
                }
            }
        }
        for(int i=0;i<str.size();i++){
            if(i+cord[i] > str.size()){continue;}
            dp[i+cord[i]] = max(dp[i+cord[i]],dp[i] + cord[i]);
        }
    }
    for(int i=0;i<str.size();i++){
        dp[i+1] = max(dp[i+1],dp[i]);
    }
    cout << dp[str.size()];
}