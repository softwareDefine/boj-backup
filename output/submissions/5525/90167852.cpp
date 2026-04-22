#define fastio cin.tie(0)->sync_with_stdio(false);
#include <iostream>

using namespace std;

int n;
int m;
string s;
int dp[1100000];
int cnt;

int main(){
    fastio;
    cin >> n;
    n = n*2+1;
    cin >> m;
    cin >> s;
    for(int i=1;i<s.length();i++){
        if(s[i] != s[i-1]){
           dp[i] = dp[i-1] + 1;
        }
    }
    for(int i=0;i<s.length();i++){
        if(s[i] == 'I'  && dp[i] >= n){
            cnt++;
        }
    }
    cout << cnt;
}
