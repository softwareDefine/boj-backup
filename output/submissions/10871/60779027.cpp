#include <stdio.h>

//N과 x; N중에 x보다 작은수들만 출력
int main(){
	
	int N, x, y, i, cnt = 0, num[10000] = {0, };
	
	scanf("%d %d", &N, &x);
	
	for(i = 0; i < N; i++){
		
		scanf("%d", &y);
		
		if(y < x){
			
			num[cnt] = y;
			cnt++;
		}
		
		else{
		}
		
	}
	
	for(i = 0; i < cnt; i++){
		
		printf("%d ", num[i]);
	}
	
}