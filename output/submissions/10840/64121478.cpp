#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define mod 524287

using ll = long long;
using namespace std;

vector<ll> vc;
string str,ptr;
int checkprime[100010];
map<pair<ll,ll>,ll> mp;
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
        ll y = 1;
        for(int j=i;j<str.length();j++){
            x = (x * vc[str[j]-'a']%mod + mod)%mod ;
            y = (y * vc[str[j]-'a'+26]%mod + mod)%mod ;
            mp[{x,y}]=j-i+1;
        }
    }
    for(int l=0;l<ptr.length();l++){
        ll x = 1;
        ll y = 1;
        for(int k=l;k<ptr.length();k++){
            x = (x * vc[ptr[k]-'a']%mod + mod)%mod;
            y = (y * vc[ptr[k]-'a'+26]%mod + mod)%mod;
            if(mp[{x,y}]==k-l+1){
                mmx = max(mmx,k-l+1);
            }
        }
    }
    cout << mmx;
}