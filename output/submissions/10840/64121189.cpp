#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define mod 1000000000000034569

using ll = long long;
using namespace std;

vector<ll> vc;
string str,ptr;
int checkprime[100010];
map<ll,vector<ll>> mp;
int mmx;

void isprime(){
    for(int i=2;i<=100000;i++){
        if(checkprime[i]){
            continue;
        }
        vc.push_back(i);
        for(int j=2*i;j<=100000;j+=i){
            checkprime[j] = 1;
        }
    }
}


int main(){
    cin >> str;
    cin >> ptr;
    isprime();
    for(int i=0;i<str.length();i++){
        ll x = 1;
        for(int j=i;j<str.length();j++){
            x = (x * vc[(str[j]-'a')*17]%mod + mod)%mod ;
            mp[x].push_back({j-i+1});
        }
    }
    for(auto &i : mp){
        sort(i.second.begin(),i.second.end(),[&](auto a,auto b){
            return a < b;
        });
    }
    for(int l=0;l<ptr.length();l++){
        ll x = 1;
        for(int k=l;k<ptr.length();k++){
            x = (x * vc[(ptr[k]-'a')*17]%mod + mod)%mod;
            if(!mp[x].empty()){
                int idx = lower_bound(mp[x].begin(),mp[x].end(),k-l+1) - mp[x].begin();
                if(mp[x][idx] == k-l+1){
                    mmx = max(mmx, k-l+1);
                }
            }
        }
    }
    cout << mmx;
}