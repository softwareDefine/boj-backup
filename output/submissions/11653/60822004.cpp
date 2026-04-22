#include <iostream>
#include <vector>

using namespace std;
int r[100];

vector <int> factorize(int N){
    vector<int> factors;
    for(int i=2;i*i<=N;i++){
        while(N%i==0){
            factors.push_back(i);
            N/=i;
        }
    }
    if(N!=1){
        factors.push_back(N);
    }
    return factors;
}
int main()
{
    int a,b,c=0;
    cin >>a;
    auto get = factorize(a);
    for(int i=0;i<get.size();i++){
        printf("%d ",get[i]);
    }
    return 0;
}
