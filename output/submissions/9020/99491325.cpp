#include <bits/stdc++.h>

using namespace std;

int t;

int isNotPrime[20000];
vector<int> prime;

void era(){
    for(int i=2;i<=10000;i++){
        if(!isNotPrime[i]){
            prime.push_back(i);
            for(int j=i*2;j<=10000;j+=i){
                isNotPrime[j] = 1;
            }
        }
    }
}

int main(){
    era();
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int flag = 0;
        int mmn = 9999999;
        pair<int,int> mmni;
        for(auto element1 : prime){
            for(auto element2 : prime){
                if(element1 + element2 == n && mmn > abs(element1-element2) ){
                    mmn = abs(element1-element2);
                    mmni = {element1,element2};
                }
            }
        }
        cout << mmni.first << ' ' << mmni.second << '\n';
    }
}