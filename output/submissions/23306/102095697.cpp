#include <bits/stdc++.h>

using namespace std;

int n;

int head, tail;

int main(){
    ios_base::sync_with_stdio(0);
    cin >> n;
    
    cout << "? 1" << '\n'; 
    fflush(stdout);
    cin >> head;
    
    cout << "? " << n << '\n'; 
    fflush(stdout);
    cin >> tail;
    
    cout << "! ";
    if(head == tail){
        cout << 0;
        fflush(stdout);
        return 0;
    }
    if(head < tail){
        cout << 1;
        fflush(stdout);
    }else{
        cout << -1;
        fflush(stdout);
    }
    return 0;
}