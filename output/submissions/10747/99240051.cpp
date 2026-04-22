#include <bits/stdc++.h>

using namespace std;

string str,ptr;
stack<pair<char,int>> st;

vector<int> preprocessing(string ptr){
    int m = ptr.size() , j = 0;
    vector<int> pi(m+1);
    for(int i=1;i<m;i++){
        while(j > 0 && ptr[i] != ptr[j]){
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
        while(j > 0 && str[i] != ptr[j]){
            j = pi[j-1];
        }
        if(str[i] == ptr[j]){
            if(j == m-1){
                int remover = 0;
                while(!st.empty() && remover < m-1){
                    st.pop();
                    remover++;
                }
                if(!st.empty()){
                    j = st.top().second;
                }else{
                    j = 0;
                }
                continue;
            }else{
                j++;
            }
        }
        st.push({str[i],j});
    }
}

void backward(){
    if(st.empty()){ return ;}
    char a = st.top().first;
    st.pop();
    backward();
    cout << a;
}

int main(){
    cin >> str;
    cin >> ptr;
    kmp(str,ptr);
    backward();
}