#include <stdio.h>

int main()
{
   int a=0,b=0,c=0,d=0,e=0,i=0,j=0,k=0,m=0,sum[10]={0};
   scanf("%d %d",&a,&b);

   for(i=0;i<a;i++){
    scanf("%d",&sum[i]);
   }
   for(j=a-1;j>=0;j--){
    if(sum[j]<=b){
        k=k+(b/sum[j]);
        b=b-(b/sum[j])*sum[j];
    }
   }
    printf("%d",k);

    return 0;
}
