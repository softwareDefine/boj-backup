#define mod 1234567891
#include <iostream>

using namespace std;

int len;
long long power = 1;
long long sum = 0;
string str;

int main(){
    cin >> len;
    cin >> str;
    for(int i=0;i<len;i++){
        sum = (sum + (str[i]-'a'+1) * power)%mod;
        power = (power *31)%mod;
    }
    cout << sum;
}