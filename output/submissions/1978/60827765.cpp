#include <iostream>

using namespace std;
int r[100];

int finder(int n){
    if(n==1){
        return 0;
    }
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}
int main()
{
    int a,b,c=0;
    cin >>a;
    for(int i=0;i<a;i++){
        scanf("%d",&b);
        if(finder(b)==1){
            c++;
        }else{
        }
    }
    printf("%d",c);
    return 0;
}
