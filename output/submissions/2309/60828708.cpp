#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

int main()
{
    int a,b[9],c=0,i,j,k;
    for(a=0;a<9;a++){
        scanf("%d",&b[a]);
        c+=b[a];
    }
    for(i=0;i<9;i++){
            for(j=0;j<9;j++){
                if(i==j){

                }
                else if(c-b[i]-b[j]==100){
                    b[i]=-1;
                    b[j]=-1;

                    i=10,j=10;
                }
            }

    }
    sort(b,b+9);
    for(a=2;a<9;a++){
            printf("%d \n",b[a]);


    }
    return 0;
}
