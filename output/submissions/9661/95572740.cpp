#include <bits/stdc++.h>

using namespace std;

unsigned long long n;


int main(){
    cin >> n;
    if(n % 5 == 0 || n % 5 == 2){
        cout << "CK";
    }else{
        cout << "SK";
    }
}