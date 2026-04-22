#include<stdio.h>
#include<algorithm>

using namespace std;
int mmx = -9999999;
int temp;
int cnt[1000001] = { 0, };
int num;
int cmp(int a,int b)
{
	if (a>b){
		return 1;
	}
	return 0;
}

int main(){
	
	scanf("%d", &num);
	for (int i = 0; i < num ; i++){
		scanf("%d", &cnt[i]);
	}
	sort(cnt, cnt + num,cmp);
	for (int i = 0; i < num; i++){
		printf("%d\n", cnt[i]);
	}
}