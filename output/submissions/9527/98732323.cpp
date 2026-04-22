#include <bits/stdc++.h>

using lint = long long;
using namespace std;

lint a;
lint b;
string atr;
string btr;

lint arr[500000];
lint sum[500000];
lint ppow[500];

lint ans;

string to_binary_min(unsigned long long x) {
    if (x == 0) return "0";
    std::string s = std::bitset<500>(x).to_string();
    auto pos = s.find('1'); 
    return s.substr(pos); 
}

int main(){
    arr[0] = 1;
    ppow[0] = 1;
    for(int i=1;i<=500;i++){
        ppow[i] = 2*ppow[i-1];
        arr[i] = ppow[i] + arr[i-1]*2;
    }
    cin >> a >> b;
    a-=1;
    atr = to_binary_min(a);
    btr = to_binary_min(b);
    lint total = 0;
    for(int i=0;i<btr.size();i++){
        if(btr[i] == '1'){
            if(i != btr.size()-1){
                ans += (arr[btr.size()-i-2]) + total*ppow[btr.size()-i-1];
            }else{
                ans += (total);
            }
            total++;
        }
    }
    ans += total;
    total = 0;
    for(int i=0;i<atr.size();i++){
        if(atr[i] == '1'){
            if(i != atr.size()-1){
                ans -= arr[atr.size()-i-2] + total*ppow[atr.size()-i-1];
            }else{
                ans -= (total);
            }
            total++;
        }
    }
    ans -= total;
    cout << ans;
}