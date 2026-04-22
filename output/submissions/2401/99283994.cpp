#include <bits/stdc++.h>

using namespace std;

int n;

string str;
vector<int> cord[1000000];
string ptr[100000];

int pi[1000000];
int dp[1000000];
int main(){
    cin >> str;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> ptr[i];
    }
    int j;
    for(int t=0; t<n; t++){
        memset(pi,0,sizeof(pi));
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
                    cord[i-ptr[t].size()+1].push_back(ptr[t].size());
                    j = pi[j];
                }else{
                    ++j;
                }
            }
        }
    }
    for(int i=0;i<str.size();i++){
        for(auto element : cord[i]){
            if(i+element > str.size()){continue;}
            dp[i+element] = max(dp[i+element],dp[i] + element);
        }
        dp[i+1] = max(dp[i+1],dp[i]);
    }
    cout << dp[str.size()];
}