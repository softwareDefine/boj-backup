#include <bits/stdc++.h>

using namespace std;

int n;

int num;

bool isPrime(int num){
    if(num < 2){return 0;}
    for(int i=2;i*i<=num;i++){
        if(num%i == 0){
            return 0;
        }
    }
    return 1;
}

void go(int now){
    if(now == n){
        cout << num << '\n';
        return;
    }
    for(int i=1;i<=9;i++){
        num *= 10; num += i;
        if(isPrime(num)){
            go(now+1);
        }
        num /= 10;
    }
}

int main(){
    cin >> n;
    go(0);
}