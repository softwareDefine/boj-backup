#include <bits/stdc++.h>

using namespace std;

string isbn;
int where;
int sum;

int main(){
    cin >> isbn;
    for(int i=0;i<isbn.size();i++){
        if(isbn[i] == '*'){
            where = i;  
            continue;}
        if(i%2){
            sum += (isbn[i] - '0')*3;
        }else{
            sum += (isbn[i] - '0');
        }
    }
    if(where%2){
        cout << ((10 - (sum % 10))%10)/3;
    }else{
        cout << (10 - (sum % 10))%10;
    }
}