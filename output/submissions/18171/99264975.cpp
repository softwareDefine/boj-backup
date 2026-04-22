#include <bits/stdc++.h>

using namespace std;

int n;
string str;
string revstr;

vector<int> preprocessing(string ptr){
    int m = ptr.size(), j = 0;
    vector<int> pi(m+1);
    pi[0] = 0;
    for(int i=1;i<m;i++){
        while( j > 0 && ptr[i] != ptr[j]){
            j = pi[j-1];
        }
        if(ptr[i] == ptr[j]){
            pi[i] = ++j;
        }else{
            pi[i] = 0;
        }
    }
    return pi;
}

void kmp(string str,string ptr){
    int n = str.size(), m = ptr.size(), j = 0;
    vector<int> pi = preprocessing(ptr);
    for(int i=0;i<n;i++){
        while( j > 0 && str[i] != ptr[j]){
            j = pi[j-1];
        }
        if(str[i] == ptr[j]){
            if(i == n-1){
                cout << m-1-j;
                return;
            }else{
                j++;
            }
        }
    }
}

int main(){
    cin >> n;
    cin >> str;
    revstr = str;
    reverse(revstr.begin(),revstr.end());
    kmp(str,revstr);
}