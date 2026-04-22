#include <bits/stdc++.h>

using namespace std;

int t;

int isNotPrime[20000];
int ans[20000];
pair<int,int> ansi[20000];
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
    fill(ans,ans+20000,9999999);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    era();
    for(auto element1 : prime){
        for(auto element2 : prime){
            if(ans[element1+element2] > abs(element1-element2)){
            ans[element1+element2] = abs(element1-element2);
            ansi[element1+element2] = {element1,element2};   
            }
        }
    }
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << ansi[n].first << ' ' << ansi[n].second << '\n';
    }
}