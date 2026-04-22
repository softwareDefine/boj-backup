#include <stdio.h>

int main()
{
    int i=0,j=0,k=0,m=0,r=0,a[100]={0},b=0,l=0,n=0;//n=최대ㅐ값
    scanf("%d %d",&r,&b);
    for(i=0;i<r;i++){
        scanf("%d",&a[i]);
    }

    for(j=0;j<r;j++){
        for(k=j+1;k<r;k++){
            for(m=k+1;m<r;m++){
                    l=a[j]+a[k]+a[m];
                    if(l > n&& l <= b){
                        n =l;
                    }

            }
        }
    }
            printf("%d",n);

    return 0;
}
