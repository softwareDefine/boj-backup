#include <bits/stdc++.h>

using namespace std;

int t;
int arr[6];
int brr[6];
int used[66];
int change[66];
set<int> st;
vector<int> vc;

int main(){
    cin >> t;
    // 암호화
    if( t == 1){
        for(int i = 0; i < 6; i++){
            cin >> arr[i];
            st.insert(arr[i]);
            used[arr[i]] = 1;
        }
        for(auto element : st){
            int move = element;
            while(used[move]){ move= (move)%64 +1 ; }
            vc.push_back(move);
            used[move] = 1;
        }
        sort(vc.begin(),vc.end());
        int cnt = 0;
        for(auto element : st){
            change[element] = vc[cnt++];
        }
        for(int i = 0; i < 6; i++){
            cout << change[arr[i]] << ' ';
        }
        cout << '\n';
    }
    // 복호화
    else{
        for(int i = 0; i < 6; i++){
            cin >> arr[i];
            st.insert(arr[i]);
            used[arr[i]] = 1;
        }
        for(auto element : st){
            int move = element;
            while(used[move]){ move= (move-1)%64; if(move ==0){move =64;} }
             vc.push_back(move);
            used[move] = 1;
        }
       sort(vc.begin(),vc.end());
        int cnt = 0;
        for(auto element : st){
            change[element] = vc[cnt++];
        }
        for(int i = 0; i < 6; i++){
            cout << change[arr[i]] << ' ';
        }
        cout << '\n';
    }
}