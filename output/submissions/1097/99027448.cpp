#include <bits/stdc++.h>

using namespace std;

int n;

string str[10];
int used[10];

string mover;
string pattern;

int k;
int cnt;

vector<int> preprocessing(string pattern){
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
  return pi;
}

bool kmp(string pattern,string str){
    int n = str.size(), m = pattern.size(), j = 0, same = 0;
    vector<int> pi = preprocessing(pattern);
    for(int i=0;i<n-1;i++){
        while(j > 0 && str[i] != pattern[j]){
            j = pi[j-1];
        }
        if(str[i] == pattern[j]){
            if(j == m-1){
                same++;
                j = pi[j];
            }else{
                j++;
            }
        }
    }
    return (same == k);
}

void go(int now){
    if(now == n){
        mover = pattern + pattern;
        if(kmp(pattern,mover)){
            cnt++;
        }
        return;
    }
    for(int i=0;i<n;i++){
        if(!used[i]){
            used[i] = 1;
            pattern += str[i];
            go(now+1);
            used[i] = 0;
            pattern = pattern.substr(0,pattern.length()-str[i].length());
        }
    }
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> str[i];
    }
    cin >> k;
    go(0);
    cout << cnt;
}