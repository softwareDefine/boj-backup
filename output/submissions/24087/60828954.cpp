#include <iostream>
#include <math.h>


using namespace std;

long long a,b,c,sum,cnt;
int main(){
    cin >> c>> a >>b ;
    
    sum = 250;
    cnt =a;
    while(c > cnt){
        cnt+=b;
        sum+=100;
    }
    cout << sum;
    }