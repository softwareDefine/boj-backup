#include <iostream>
#include <string>

using namespace std;

string a[3];
int cnt = 0;

int main(){
    for(int i=0;i<3;i++){
        cin >> a[i];
    }
    for(int i=0;i<3;i++){
        if(a[i] == "Fizz" || a[i] == "Buzz" || a[i] == "FizzBuzz"){
            cnt++;
        }else{
            cnt = stoi(a[i]);
        } 
    }
    cnt++;
    if(cnt % 15 == 0){
        cout << "FizzBuzz";
    }else if(cnt % 5 == 0){
        cout << "Buzz";
    }else if(cnt % 3 == 0){
        cout << "Fizz";
    }else{
        cout << cnt;
    }
}