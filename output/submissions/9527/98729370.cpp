#include <bits/stdc++.h>

using lint = long long;
using namespace std;

lint a;
lint b;
string atr;
string btr;

lint arr[500000];
lint sum[500000];

lint ans;

string to_binary_min(unsigned long long x) {
    if (x == 0) return "0";
    std::string s = std::bitset<500>(x).to_string();
    auto pos = s.find('1'); 
    return s.substr(pos); 
}

int main(){
    arr[0] = 1;
    for(int i=1;i<=500;i++){
        arr[i] = pow(2,i) + arr[i-1]*2;
    }
    cin >> a >> b;
    a-=1;
    atr = to_binary_min(a);
    btr = to_binary_min(b);
    reverse(atr.begin(),atr.end());
    reverse(btr.begin(),btr.end());
    for(int i=0;i<btr.size();i++){
        if(btr[i] == '1'){
            if(i-1 >=0 ){
                ans += (arr[i-1] + 1)*pow(2,btr.size()-i-1);
            }else{
                ans += 2*pow(2,btr.size()-i-1);
            }
        }
        //cout << ans << ' ';
    }
    for(int i=0;i<atr.size();i++){
        if(atr[i] == '1'){
            if(i-1 >=0 ){
                ans -= (arr[i-1] + 1)*pow(2,atr.size()-i-1);
            }else{
                ans -= 2*pow(2,atr.size()-i-1);
            }
        }
        //cout << ans << ' ';
    }
    cout << ans;
}