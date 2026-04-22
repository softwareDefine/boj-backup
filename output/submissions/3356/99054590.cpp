#include <bits/stdc++.h>

using namespace std;

int n;
string pattern;

void preprocessing(string pattern){
    int m = pattern.size(), j = 0;
    vector<int> pi(m+1);
    pi[0] = 0;
    for(int i=1;i<m;i++){
        while(j > 0 && pattern[i] != pattern[j]){
            j = pi[j-1];
        }
        if(pattern[i] == pattern[j]){
            pi[i] = ++j;
        }else{
            pi[i] = 0;
        }
    }
    int last = pattern.size();
    for(int i=0;i<m-1;i++){
        if(pi[i] == 1){
            last = i;
        }
    }
    cout << last;
}

int main(){
    cin >> n;
    cin >> pattern;
    preprocessing(pattern);
}