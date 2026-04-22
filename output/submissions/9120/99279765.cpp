#include <bits/stdc++.h>

using namespace std;

int t;

string str, ptr;

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
        }
    }
    return pi;
}

int kmp(string str,string ptr){
    int n = str.size(), m = ptr.size(), j = 0, cnt = 0;
    vector<int> pi = preprocessing(ptr);
    for(int i=0;i<n;i++){
        while( j > 0 && str[i] != ptr[j]){
            j = pi[j-1];
        }
        if(str[i] == ptr[j]){
            if( j == m-1 ){
                j = pi[j];
                cnt++;
            }else{
                j++;
            }
        }
    }
    return cnt;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> t;
    while(t--){
        cin >> ptr;
        cin >> str;
        cout << kmp(str,ptr) << '\n';
    }
}