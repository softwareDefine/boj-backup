#include <bits/stdc++.h>

using namespace std;

string isbn;
int sum;

int main(){
    cin >> isbn;
    for(int i=0;i<isbn.length();i++){
        if(isbn[i] == '*'){continue;}
        if(i%2){
            sum += (isbn[i] - '0')*3;
        }else{
            sum += (isbn[i] - '0');
        }
    }
    cout << (10 - sum % 10)%10;
}