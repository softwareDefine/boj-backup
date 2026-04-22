#include <stdio.h>
//첫째 줄부터 N번째 줄 까지 차례대로 별을 출력한다.
int main(){
    
    int i, j, N;
    
    scanf("%d", &N);
    
    for(i = 1; i <= N; i++){
        
        for(j = N; j >= i; j--){
            
            printf("*");
        }
        
        puts("");
    }
    
}