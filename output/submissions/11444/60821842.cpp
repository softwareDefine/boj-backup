#include <iostream>
#include <map>

using namespace std;

map<long long, long long> dic;

const long long DIV =1000000007LL;

long long fibo(long long n){
    if (n<0) cout << "n<0\n";
    if (n==0) return 0;
    else if (n==1) return 1;
    else if (dic[n] > 0) return dic[n];
    else if (n%2==0) {
        long long m = n/2;
        long long temp1 = fibo(m-1);
        long long temp2 = fibo(m);
        dic[n] = (2LL*temp1+temp2)*temp2;
        dic[n] %= DIV;
        return dic[n];
    }
    else {
        long long m = (n+1)/2;
        long long temp1 = fibo(m);
        long long temp2 = fibo(m-1);
        dic[n] = temp1*temp1 + temp2*temp2;
        dic[n] %= DIV;
        return dic[n];
    }
}

int main(int argc, const char * argv[]) {
    
    long long N;
    cin >> N;
    
    cout <<  fibo(N) << "\n";
    return 0;
}