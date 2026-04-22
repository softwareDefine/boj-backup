#include <iostream>
#include <vector>
int cnt;
using namespace std;
int fn[1010][1010];
int dd(int n,int r){
    if(n==r){
        return 1;
    }
    if(r==0){
        return 1;
    }
    if(fn[n][r]!=0){
        return fn[n][r];
    }
    return fn[n][r]=(dd(n-1,r-1)+dd(n-1,r))%10007;
}

int main()
{
    int n,k;
    cin >> n >> k;
    printf("%d",dd(n,k));
    return 0;
}
