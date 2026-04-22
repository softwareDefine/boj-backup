#include <iostream>
#include <math.h>


using namespace std;

long long a,b,sum;
int main(){
    cin >> a >>b;
    sum = a+b;
    while(sum >12)
        sum-=12;
    cout << sum;
    }