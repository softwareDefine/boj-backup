#include<stdio.h>

int main(){
    int cnt[10001]={0, };
    int a;
    int temp=0;
    scanf("%d",&a);
    
    for(int i=0;i<a;i++){
        scanf("%d",&temp);
        cnt[temp]++; 
    }
    for(int i=0;i<10001;i++){
        for(int j=0;j<cnt[i];j++){
            printf("%d\n",i);
        }
    }
}