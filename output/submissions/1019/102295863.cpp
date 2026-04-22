#include <bits/stdc++.h>

using lint = long long;
using namespace std;

int n;

int cnt[10];

int length = 0;

int main() {
    cin >> n;
    int chker = n;
    while(chker){
        chker/= 10;
        length++;
    }
    for(int i = 0; i < length; i++){
        for(int t = 0; t < 10; t++){
            if(t == 0 && n/int(pow(10, i+1))){
                cnt[t] += (n/int(pow(10, i+1))-1) * int(pow(10,i));
                continue;
            }
            cnt[t] += n/int(pow(10, i+1)) * int(pow(10,i));
        }
        int start = 1;
        if(n/int(pow(10, i+1))){
            start = 0;
        }
        for(int t = start; t < n/int(pow(10, i))%10; t++){
            cnt[t] += int(pow(10,i));
        }
        cnt[n/int(pow(10, i))%10] += n%int(pow(10, i))+1;
    }
    
        for(int t = 0; t < 10; t++){
            cout << cnt[t] << ' ';
        }
    return 0;
}