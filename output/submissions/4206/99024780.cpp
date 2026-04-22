#include <bits/stdc++.h>

using lint = long long;
using namespace std;

lint n;

struct node{
    string front;
    string middle;
    string end;
};

lint t;
string pattern;
vector<lint> pi(200000);

void preprocessing(string pattern){
    lint n = pattern.size() , j = 0;
    pi[0] = 0;
    for(int i=1;i<n;i++){
        while(j > 0 && pattern[i] != pattern[j]){
            j = pi[j-1];
        }
        if(pattern[i] == pattern[j]){
            pi[i] = ++j;
        }else{
            pi[i] = 0;
        }
    }
}

lint kmp(string pattern,string str){
    lint cnt = 0;
    lint n = str.size(), m = pattern.size(), j = 0;
    for(lint i=0;i<n;i++){
        while(j > 0 && str[i] != pattern[j]){
            j = pi[j-1];
        }
        if(str[i] == pattern[j]){
            if(j == m-1){
                cnt++;
                j = pi[j];
            }else{
                j++;
            }
        }
    }
    return cnt;
}

node fibbo[200];
lint dp[200];

int main(){
    while(cin >> n){
        cin >> pattern;
        preprocessing(pattern);
        fibbo[0] = {"0","","0"};
        dp[0] = kmp(pattern,"0");
        fibbo[1] = {"1","","1"};
        dp[1] = kmp(pattern,"1");
        for(int i=2;i<=n;i++){
            fibbo[i].middle = fibbo[i-1].end.substr(max(int(fibbo[i-1].end.length()-pattern.size()+1),0)) + fibbo[i-2].front.substr(0,min(int(fibbo[i-2].front.length()),int(pattern.size()-1)));
            fibbo[i].front = (fibbo[i-1].front + fibbo[i-2].front).substr(0,min((fibbo[i-1].front + fibbo[i-2].front).length(),pattern.size()-1));
            fibbo[i].end = (fibbo[i-1].end + fibbo[i-2].end).substr(max(0,int((fibbo[i-1].end + fibbo[i-2].end).length()-pattern.size()+1)));
            //cout << fibbo[i-1].end.substr(max(int(fibbo[i-1].end.length()-pattern.size()+1),0)) << ' ' <<  fibbo[i-2].front.substr(0,min(int(fibbo[i-2].front.length()),int(pattern.size()-1)))<< '\n';
            dp[i] = dp[i-1] + dp[i-2] + kmp(pattern,fibbo[i].middle);
        }
        cout << "Case " << ++t << ": " << dp[n] << '\n';
    }
}