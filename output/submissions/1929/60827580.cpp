#include <iostream>
#include <vector>
int cnt;
using namespace std;
int fn[1010000];
int main()
{
    int m,n;
    cin >>m>>n;
    for(int i=2;i<=n;i++){
        if(fn[i]==1){
            continue;
        }

        for(int j=i*2;j<=n;j+=i){
            fn[j]=1;
        }
    }
    for(int i=m;i<=n;i++){
        if(i==1){
            continue;
        }
        if(fn[i]==0){
            printf("%d\n",i);
        }

    }
    return 0;
}
