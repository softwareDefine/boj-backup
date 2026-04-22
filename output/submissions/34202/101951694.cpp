#include <bits/stdc++.h>

using namespace std;

int n;

int arr[210000];

stack<int> st;

int main(){
    cin >> n;
    for(int i = 1; i <= n-1; i++){
        cin >> arr[i];
    }
    cout << 1 << ' ';
    for(int i = 1; i <= n-2; i++){
        int diff = arr[i+1]-arr[i];
        if(diff == 2){
            st.push(i+1);
        }else if(diff == -2){
            cout << i+1 << ' ' << st.top() << ' ';
            st.pop();
        }else{
            cout << i+1 << ' ';
        }
    }
    cout << n << ' ';
}